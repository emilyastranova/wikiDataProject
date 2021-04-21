#include "wikiEntry.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // In the future this will be inside a loop where inputString is just the input from .dat file
    string inputString = "13576300:156567:Hogwarts School Of Witchcraft And Wizardry";

    // Test having a map of wikiEntrys
    // map<title, wikiEntry datatype (including namespace and ID)>
    // Using wikiEntry function parseTitle() to avoid making another wikiEntry in memory ex. "wikiEntry(inputString).title"
    map<string, wikiEntry> entries;
    insertEntry(entries, inputString);
    // Some more test strings for fun
    insertEntry(entries, "13576300:156542:The Arrival (The Twilight Zone)");
    insertEntry(entries, "13576300:156544:Cian Ciaran");
    insertEntry(entries, "13576300:156545:B-sides");
    insertEntry(entries, "13576300:156546:Stepin Fetchit");
    insertEntry(entries, "13576300:156547:Remix");
    insertEntry(entries, "13576300:156548:Gruff Rhys");

    // showing contents:
    map<string, wikiEntry>::iterator it = entries.begin();
    for (it = entries.begin(); it != entries.end(); ++it) {
        cout << "\nName: " << it->first << endl;
        cout << "NS: " << it->second.pairType.first  << endl;
        cout << "ID: " << it->second.pairType.second << endl;
    }

}