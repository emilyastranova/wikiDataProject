#include <utility>
#include <algorithm>
#include "../wikiEntrySpike/wikiEntry.h"
using namespace std;



int main() {
    
    vector<wikiEntry> wikiEntryList = {
        makeEntry("43658487", "166067", "title"),
        makeEntry("300907853", "277592", "title"),
        makeEntry("66679025", "172583", "title"),
        makeEntry("233152987", "242099", "title"),
        makeEntry("207724733", "231119", "title"),
        makeEntry("89800554", "180741", "title"),
        makeEntry("247065992", "249093", "title"),
        makeEntry("186657846", "221256", "title")
        
    };

    vector<wikiEntry>::iterator it = wikiEntryList.begin();
    cout << "PRE SORT:" << endl;
    for (it = wikiEntryList.begin(); it != wikiEntryList.end(); ++it) {
        it->printEntry();
    }
    
    
    cout << endl;

    sort(wikiEntryList.begin(), wikiEntryList.end());

    cout << "POST SORT:" << endl;
    for (it = wikiEntryList.begin(); it != wikiEntryList.end(); ++it) {
        it->printEntry();
    }

}
