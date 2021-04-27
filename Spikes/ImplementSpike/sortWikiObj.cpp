#include <utility>
#include <algorithm>
#include "../wikiEntrySpike/wikiEntry.h"
using namespace std;



int main() {
    
    vector<wikiEntry> wikiEntryList = {
        wikiEntry("title3", "43658487", "166069"),
        wikiEntry("title", "43658487", "166067"),
        wikiEntry("title2", "43658487", "166068"),
        wikiEntry("title4", "43658489", "166069"),
        
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
