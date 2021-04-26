#include <iostream>
#include <map>
#include <vector>

#include "../wikiEntrySpike/wikiEntry.h"

using namespace std;

int main() {
    bool unitTest1 = false; // Test < operator
    bool unitTest2 = false; // Test == operator

    wikiEntry testEntry = wikiEntry("13576300:156567:Duplicate Test");
    wikiEntry testEntryDuplicate = wikiEntry("13576300:156567:Duplicate Test 2");

    wikiEntry entry1 = wikiEntry("13576300:156544:The Arrival (The Twilight Zone)");
    wikiEntry entry2 = wikiEntry("13576301:156546:Cian Ciaran");

    entry1.printEntry();
    cout << endl;
    entry2.printEntry();
    cout << endl << endl;

    if (entry1 < entry2)
        cout << entry1.title << " < " << entry2.title;
    else
        cout << entry1.title << " > " << entry2.title;

    cout << endl << endl;
    cout << testEntry.title << " == " << testEntryDuplicate.title << ": ";
    if (testEntry == testEntryDuplicate)
        cout << "True\n";
    else
        cout << "False\n";

    cout << "\n|-------------------|\n" << "|   Unit Testing:   |" << endl << "|-------------------|" << endl;
    if (entry1 < entry2)
        cout << " [<]  Operator: [P]" << endl;
    else
        cout << " [<]  Operator: [F]" << endl;
    if (testEntry == testEntryDuplicate)
        cout << " [==] Operator: [P]" << endl;
    else
        cout << " [==] Operator: [F]" << endl;

    if (entry1 < entry2 && testEntry == testEntryDuplicate)
        cout << "\nCongratulations C Team!" << endl;
}