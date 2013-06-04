/*
 * Apache Felix OSGi tutorial.
 **/

package tutorial.example2b;

import java.util.Hashtable;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

import tutorial.example2.service.DictionaryService;

/**
 * This class implements a simple bundle that uses the bundle context to
 * register an French language dictionary service with the OSGi framework. The
 * dictionary service interface is defined in a separate class file and is
 * implemented by an inner class. This class is identical to the class in
 * Example 2, except that the dictionary contains French words.
 **/
public class Activator implements BundleActivator {
    public void start(BundleContext context) {
        Hashtable<String, String> props = new Hashtable<String, String>();
        props.put("Language", "French");
        context.registerService(DictionaryService.class.getName(),
                new DictionaryImpl(), props);
    }

    public void stop(BundleContext context) {
        // NOTE: The service is automatically unregistered.
    }

    private static class DictionaryImpl implements DictionaryService {
        // The set of words contained in the dictionary.
        String[] m_dictionary = { "bienvenue", "au", "tutoriel", "osgi" };

        /**
         * Implements DictionaryService.checkWord(). Determines if the passed in
         * word is contained in the dictionary.
         * 
         * @param word
         *            the word to be checked.
         * @return true if the word is in the dictionary, false otherwise.
         **/
        public boolean checkWord(String word) {
            word = word.toLowerCase();

            // This is very inefficient
            for (int i = 0; i < m_dictionary.length; i++) {
                if (m_dictionary[i].equals(word)) {
                    return true;
                }
            }
            return false;
        }
    }
}
