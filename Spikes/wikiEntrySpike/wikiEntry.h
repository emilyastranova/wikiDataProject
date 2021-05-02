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
    // Parses strings into a vector of strings with the delimiter space ' '.
    void parseInput(string &userInput, vector<string> &stringVector); 
    // Outputs to a vector of vectors containing wiki entries that match search terms.
    void searchMatch(map<string, wikiEntry> &entries, vector<string> &stringVector, vector<vector<wikiEntry>> &matchedVector);
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
    // Lars Implementation Below:
    if (stoi(this->pairType.first) < stoi(other.pairType.first) || stoi(this->pairType.second) < stoi(other.pairType.second)) {
        return true;
    } else {
        return false;
    }
    
    // Truman's Implementation Below:
    // return (
    //   make_pair(stoi(this->pairType.first), stoi(this->pairType.second))
    //   <
    //     make_pair(stoi(other.pairType.first), stoi(other.pairType.second))
    //  );
}

void parseInput(string &userInput, vector<string> &stringVector) {
    string temp;
    stringstream stream(userInput); // converts string to a stringstream for use in getline()

    while(getline(stream, temp, ' ')) { // breaks strings into tokens that are pushed into stringVector.
        stringVector.push_back(temp);
    } 
}

void searchMatch(map<string, wikiEntry> &entries, vector<string> &stringVector, vector<vector<wikiEntry>> &searchedVector) {
    vector<wikiEntry> internalVector;

    // Searches for entries with titles that match search terms.
    // Pushes found entries into a vector of vectors that store each term's matches.
    for (int i = 0; i < stringVector.size(); ++i) { 
        search(entries, stringVector.at(i), internalVector);
        searchedVector.push_back(internalVector);
        internalVector.clear();
    }

    // example for iterating through vector of vectors
    // has printEntry & couts for testing purposes
    for (int i = 0; i < searchedVector.size(); ++i) {
        cout << "----------------------" << endl;
        cout << "searchedVector Index " << i << endl;
        cout << "----------------------" << endl;
        for (int j = 0; j < searchedVector.at(i).size(); ++j) {
            cout << "*Internal Vector Index " << j << '*' << endl;
            searchedVector.at(i).at(j).printEntry();
            cout << endl;
        }
    }
}

#endif
