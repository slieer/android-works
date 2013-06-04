/*
 * Apache Felix OSGi tutorial.
 **/

package tutorial.example2;

import java.util.Hashtable;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

import tutorial.example2.service.DictionaryService;

/*
 * 
 */
public class Activator implements BundleActivator {
    public void start(BundleContext context) {
        Hashtable<String, String> props = new Hashtable<String, String>();
        props.put("Language", "English");
        context.registerService(DictionaryService.class.getName(),
                new DictionaryImpl(), props);
        
        System.out.println("Start dictionary service ...");
    }

    public void stop(BundleContext context) {
        // NOTE: The service is automatically unregistered.
    }

    private static class DictionaryImpl implements DictionaryService {
        // The set of words contained in the dictionary.
        String[] m_dictionary = { "welcome", "to", "the", "osgi", "tutorial" };

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
