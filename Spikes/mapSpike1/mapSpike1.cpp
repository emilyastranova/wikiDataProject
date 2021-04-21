#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

int main() {
    std::map<std::string, std::string> wikiTitles;

    // wikiTitles.insert(std::pair<std::string, std::string>("howdy", "101"));
    // wikiTitles.insert(std::pair<std::string, std::string>("texas", "102"));
    // wikiTitles.insert(std::pair<std::string, std::string>("howdy", "103"));

    wikiTitles["howdy"] = "101";
    wikiTitles["texas"] = "102";
    wikiTitles["howdy"] = "103";

    std::map<std::string, std::string>::iterator it = wikiTitles.begin();

    // showing contents:
    for (it = wikiTitles.begin(); it != wikiTitles.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    return 0;
}