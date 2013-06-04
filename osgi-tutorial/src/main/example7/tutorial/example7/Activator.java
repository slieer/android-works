/*
 * Apache Felix OSGi tutorial.
**/

package tutorial.example7;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;
import org.osgi.util.tracker.ServiceTracker;

import tutorial.example6.service.SpellChecker;

public class Activator implements BundleActivator
{
    // Bundle's context.
    private BundleContext m_context = null;
    // The service tacker object.
    private ServiceTracker m_tracker = null;

    public void start(BundleContext context) throws Exception
    {
        m_context = context;

        // Create a service tracker to monitor dictionary services.
        m_tracker = new ServiceTracker(
            m_context,
            m_context.createFilter(
                "(objectClass=" + SpellChecker.class.getName() + ")"),
            null);
        m_tracker.open();

        try
        {
            System.out.println("Enter a blank line to exit.");
            String passage = "";
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

            // Loop endlessly.
            while (true)
            {
                // Ask the user to enter a passage.
                System.out.print("Enter passage: ");
                passage = in.readLine();

                // Get the selected dictionary service, if available.
                SpellChecker checker = (SpellChecker) m_tracker.getService();

                // If the user entered a blank line, then
                // exit the loop.
                if (passage.length() == 0)
                {
                    break;
                }
                // If there is no spell checker, then say so.
                else if (checker == null)
                {
                    System.out.println("No spell checker available.");
                }
                // Otherwise check passage and print misspelled words.
                else
                {
                    String[] errors = checker.check(passage);

                    if (errors == null)
                    {
                        System.out.println("Passage is correct.");
                    }
                    else
                    {
                        System.out.println("Incorrect word(s):");
                        for (int i = 0; i < errors.length; i++)
                        {
                            System.out.println("    " + errors[i]);
                        }
                    }
                }
            }
        } catch (Exception ex) { }
    }

    /**
     * Implements BundleActivator.stop(). Does nothing since
     * the framework will automatically unget any used services.
     * @param context the framework context for the bundle.
    **/
    public void stop(BundleContext context)
    {
    }
}
