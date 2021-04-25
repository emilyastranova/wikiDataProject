//
// Created by William Hatcher on 4/23/21.
//

#include <utility>
#include <algorithm>

#include "../wikiEntrySpike/wikiEntry.h"

wikiEntry lazyMakeEntry(string ns, string id, string title) {
    return wikiEntry(std::move(title), std::move(ns), std::move(id));
}
int main() {
    vector<wikiEntry> wikiEntries = {
            lazyMakeEntry("43658487", "166067", "title"),
            lazyMakeEntry("300907853", "277592", "title"),
            lazyMakeEntry("66679025", "172583", "title"),
            lazyMakeEntry("233152987", "242099", "title"),
            lazyMakeEntry("207724733", "231119", "title"),
            lazyMakeEntry("89800554", "180741", "title"),
            lazyMakeEntry("247065992", "249093", "title"),
            lazyMakeEntry("231701098", "241714", "title"),
            lazyMakeEntry("212578740", "233342", "title"),
            lazyMakeEntry("240699153", "246147", "title"),
            lazyMakeEntry("265443003", "257621", "title"),
            lazyMakeEntry("133429249", "198058", "title"),
            lazyMakeEntry("123929477", "245107", "title"),
            lazyMakeEntry("348311637", "305183", "title"),
            lazyMakeEntry("203161898", "229147", "title"),
            lazyMakeEntry("123929477", "194323", "title"),
            lazyMakeEntry("239980909", "245795", "title"),
            lazyMakeEntry("43658487", "232817", "title"),
            lazyMakeEntry("354602575", "308096", "title"),
            lazyMakeEntry("182331940", "218844", "title"),
            lazyMakeEntry("265443003", "257654", "title")
    };

    for (const auto& item : wikiEntries ) {
        std::cout << item.pairType.first << ":" << item.pairType.second << endl;
    }

    sort(wikiEntries.begin(), wikiEntries.end());

    cout << endl << "AFTER SORT" << endl;
    for (const auto& item : wikiEntries ) {
        std::cout << item.pairType.first << ":" << item.pairType.second << endl;
    }
}
