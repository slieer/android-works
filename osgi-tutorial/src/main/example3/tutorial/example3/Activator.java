/*
 * Apache Felix OSGi tutorial.
 **/

package tutorial.example3;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;
import org.osgi.framework.ServiceReference;

import tutorial.example2.service.DictionaryService;

/**
**/
public class Activator implements BundleActivator {
    public void start(BundleContext context) throws Exception {
        // Query for all service references matching any language.
        ServiceReference[] refs = context.getServiceReferences(
                DictionaryService.class.getName(), "(Language=*)");

        if (refs != null) {
            try {
                System.out.println("Enter a blank line to exit.");
                BufferedReader in = new BufferedReader(new InputStreamReader(
                        System.in));
                String word = "";

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

                    // First, get a dictionary service and then check
                    // if the word is correct.
                    DictionaryService dictionary = (DictionaryService) context
                            .getService(refs[0]);
                    if (dictionary.checkWord(word)) {
                        System.out.println("Correct.");
                    } else {
                        System.out.println("Incorrect.");
                    }

                    // Unget the dictionary service.
                    context.ungetService(refs[0]);
                }
            } catch (IOException ex) {
            }
        } else {
            System.out.println("Couldn't find any dictionary service...");
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
}
