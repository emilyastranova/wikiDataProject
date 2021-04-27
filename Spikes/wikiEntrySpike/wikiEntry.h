#ifndef H_WIKI_ENTRY_SPIKE
#define H_WIKI_ENTRY_SPIKE
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <locale>

using namespace std;
class wikiEntry {
   private:
    /* data */
   public:
    wikiEntry(string title, string ns, string id);
    wikiEntry(string rawData);
    ~wikiEntry();

    wikiEntry makeEntry(string ns, string id, string title);
    void search(map<string, wikiEntry> entries, string userInput, vector<wikiEntry> resultVector);
    void printEntry();
    string parseTitle(string rawData);  // Used for returning the title from a raw .dat entry string
    void insertEntry(map<string, wikiEntry> &entries, string rawData);
    void insertEntry(map<string, wikiEntry> &entries, string title, string ns, string id);
    string toLower(string str); // Convert string to lowercase
    string title;
    pair<string, string> pairType;
    bool operator== (const wikiEntry &other);
    inline bool operator < (const wikiEntry& rhs) const;
};


string parseTitle(string rawData) {
    stringstream data(rawData);
    string line;
    for(int x = 0; x < 3; x++)  // Traverse to third segment of string (the title)
        getline(data, line, ':');
    return line;                // Return the line from above loop
}

string toLower(string str)
{
    string temp = str;
    for(auto& c : temp)
    {
    c = tolower(c);
    }

    return temp;

}

void search(map<string, wikiEntry> &entries, string userInput, vector<wikiEntry> &resultVector){
    map<string, wikiEntry>::iterator it;
    for (it = entries.begin(); it != entries.end(); ++it) {
        if (it->first.find(toLower(userInput)) != string::npos) {
            resultVector.insert(resultVector.begin(), wikiEntry(it->first, it->second.pairType.first, it->second.pairType.second));
        }
    }
}

void insertEntry(map<string, wikiEntry> &entries, string title, string ns, string id) {
    entries.insert(pair<string, wikiEntry>(toLower(parseTitle(title)), wikiEntry(title, ns, id)));
}

void insertEntry(map<string, wikiEntry> &entries, string rawData) {
    entries.insert(pair<string, wikiEntry>(toLower(parseTitle(rawData)), wikiEntry(rawData)));
}

void wikiEntry::printEntry()
{
    cout << "Title: " << title << "\nNamespace: " << pairType.first << "\nID: " << pairType.second << endl;
}

wikiEntry makeEntry(string ns, string id, string title) {
    return wikiEntry(title, ns, id);
}

wikiEntry::wikiEntry(string rawData) {
    string delimiter = ":";
    stringstream data(rawData);
    string line;
    getline(data, line, ':');
    pairType.first = line;
    getline(data, line, ':');
    pairType.second = line;
    getline(data, line, ':');
    this->title = line;
}

wikiEntry::wikiEntry(string title, string ns, string id) {
    pairType.first = ns;
    pairType.second = id;
    this->title = title;
}

wikiEntry::~wikiEntry() {
}

bool wikiEntry::operator==(const wikiEntry &other) {
    if (this->pairType.first == other.pairType.first
        && this->pairType.second == other.pairType.second){
        return true;
    }else {
        return false;
    }
}

bool wikiEntry::operator<(const wikiEntry &other) const {
    // Truman's Implementation Below:
    // if (stoi(this->pairType.first) < stoi(other.pairType.first) || stoi(this->pairType.second) < stoi(other.pairType.second)) {
    //     return true;
    // } else {
    //     return false;
    // }
    
    // Lars Implementation Below:
    return (
      make_pair(stoi(this->pairType.first), stoi(this->pairType.second))
      <
        make_pair(stoi(other.pairType.first), stoi(other.pairType.second))
     );
}

#endif
