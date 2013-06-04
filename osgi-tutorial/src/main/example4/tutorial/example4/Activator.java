package tutorial.example4;

/*
 * Apache Felix OSGi tutorial.
 **/

import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;
import org.osgi.framework.InvalidSyntaxException;
import org.osgi.framework.ServiceEvent;
import org.osgi.framework.ServiceListener;
import org.osgi.framework.ServiceReference;

import tutorial.example2.service.DictionaryService;

public class Activator implements BundleActivator, ServiceListener {
    // Bundle's context.
    private BundleContext m_context = null;
    // The service reference being used.
    private ServiceReference m_ref = null;
    // The service object being used.
    private DictionaryService m_dictionary = null;

    public void start(BundleContext context) throws Exception {
        m_context = context;

        // We synchronize while registering the service listener and
        // performing our initial dictionary service lookup since we
        // don't want to receive service events when looking up the
        // dictionary service, if one exists.
        synchronized (this) {
            // Listen for events pertaining to dictionary services.
            m_context
                    .addServiceListener(this, "(&(objectClass="
                            + DictionaryService.class.getName() + ")"
                            + "(Language=*))");

            // Query for any service references matching any language.
            ServiceReference[] refs = m_context.getServiceReferences(
                    DictionaryService.class.getName(), "(Language=*)");

            // If we found any dictionary services, then just get
            // a reference to the first one so we can use it.
            if (refs != null) {
                m_ref = refs[0];
                m_dictionary = (DictionaryService) m_context.getService(m_ref);
            }
        }

        try {
            System.out.println("Enter a blank line to exit.");
            String word = "";
            BufferedReader in = new BufferedReader(new InputStreamReader(
                    System.in));

            // Loop endlessly.
            while (true) {
                // Ask the user to enter a word.
                System.out.print("Enter word: ");
                word = in.readLine();

                // If the user entered a blank line, then
                // exit the loop.
                if (word.length() == 0) {
                    break;
                }
                // If there is no dictionary, then say so.
                else if (m_dictionary == null) {
                    System.out.println("No dictionary available.");
                }
                // Otherwise print whether the word is correct or not.
                else if (m_dictionary.checkWord(word)) {
                    System.out.println("Correct.");
                } else {
                    System.out.println("Incorrect.");
                }
            }
        } catch (Exception ex) {
        }
    }

    /**
     * Implements BundleActivator.stop(). Does nothing since the framework will
     * automatically unget any used services.
     * 
     * @param context
     *            the framework context for the bundle.
     **/
    public void stop(BundleContext context) {
        // NOTE: The service is automatically released.
    }

    /**
     * Implements ServiceListener.serviceChanged(). Checks to see if the service
     * we are using is leaving or tries to get a service if we need one.
     * 
     * @param event
     *            the fired service event.
     **/
    public synchronized void serviceChanged(ServiceEvent event) {
        String[] objectClass = (String[]) event.getServiceReference()
                .getProperty("objectClass");

        // If a dictionary service was registered, see if we
        // need one. If so, get a reference to it.
        if (event.getType() == ServiceEvent.REGISTERED) {
            if (m_ref == null) {
                // Get a reference to the service object.
                m_ref = event.getServiceReference();
                m_dictionary = (DictionaryService) m_context.getService(m_ref);
            }
        }
        // If a dictionary service was unregistered, see if it
        // was the one we were using. If so, unget the service
        // and try to query to get another one.
        else if (event.getType() == ServiceEvent.UNREGISTERING) {
            if (event.getServiceReference() == m_ref) {
                // Unget service object and null references.
                m_context.ungetService(m_ref);
                m_ref = null;
                m_dictionary = null;

                // Query to see if we can get another service.
                ServiceReference[] refs = null;
                try {
                    refs = m_context.getServiceReferences(
                            DictionaryService.class.getName(), "(Language=*)");
                } catch (InvalidSyntaxException ex) {
                    // This will never happen.
                }
                if (refs != null) {
                    // Get a reference to the first service object.
                    m_ref = refs[0];
                    m_dictionary = (DictionaryService) m_context
                            .getService(m_ref);
                }
            }
        }
    }
}
