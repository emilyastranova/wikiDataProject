//
// Created by William Hatcher on 4/23/21.
// Proves that you can sort pair<string, string> via sort method
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<string, string> wikiThing;

int main() {
    vector<wikiThing> set2;

    vector<wikiThing> set1 = {
            make_pair("43658487", "166067"),
            make_pair("300907853", "277592"),
            make_pair("66679025", "172583"),
            make_pair("233152987", "242099"),
            make_pair("207724733", "231119"),
            make_pair("89800554", "180741"),
            make_pair("247065992", "249093"),
            make_pair("231701098", "241714"),
            make_pair("212578740", "233342"),
            make_pair("240699153", "246147"),
            make_pair("265443003", "257621"),
            make_pair("133429249", "198058"),
            make_pair("123929477", "245107"),
            make_pair("348311637", "305183"),
            make_pair("203161898", "229147"),
            make_pair("123929477", "194323"),
            make_pair("239980909", "245795"),
            make_pair("43658487", "232817"),
            make_pair("354602575", "308096"),
            make_pair("182331940", "218844"),
            make_pair("265443003", "257654"),
    };

    for (const auto& item : set1 ) {
        std::cout << item.first << ":" << item.second << endl;
    }

    sort(set1.begin(), set1.end(),
         [] (const wikiThing& lhs, const wikiThing& rhs)
         {
             return (
                     make_pair(stoi(lhs.first), stoi(lhs.second))
                     <
                     make_pair(stoi(rhs.first), stoi(rhs.second))
             );
         });

    cout << endl << "AFTER SORT" << endl;
    for (const auto& item : set1 ) {
        std::cout << item.first << ":" << item.second << endl;
    }

}