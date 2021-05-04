#ifndef H_WIKI_ENTRY_SPIKE
#define H_WIKI_ENTRY_SPIKE
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <locale>
#include "../../wikiData.h"

using namespace std;
class wikiEntry {
   private:
    /* data */
   public:
    wikiEntry(string title, string ns, string id);
    wikiEntry(string rawData);
    ~wikiEntry();

    void getUserInput(vector<string> &userSearchTerms);
    void readInData(map<string, wikiEntry> &entries);
    void printEntryVector(vector<wikiEntry> vResult);
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

istream& operator>>(istream& str, wikiData& data) {
    data.readNextRow(str);
    return str;
}

void getUserInput(vector<string> &userSearchTerms) {
    // Credit: paddy
    // https://stackoverflow.com/questions/14347033/reading-a-sequence-of-words-to-add-them-in-a-vector
    //-------------------------------------------------------
    // Get all words on one line                            |
    cout << "Enter search term: " << flush; //              |
    string allwords; //                                     |
    getline(cin, allwords); //                              |
    //                                                      |
    // Parse words into a vector                            |
    string word; //                                         |
    istringstream iss(allwords); //                         |
    while( iss >> word ) userSearchTerms.push_back(word);// |
    //-------------------------------------------------------
}

void printEntryVector(vector<wikiEntry> vResult) {
    // Find longest result
    vector<wikiEntry>::iterator resultIt;
    int longest = 0;
    for(resultIt = vResult.begin(); resultIt != vResult.end(); ++resultIt){
        if((signed)(resultIt->title.length()) > longest)
            longest = resultIt->title.length();
    }

    if (vResult.empty())
        cout << "\nNo results found" << endl;
    else
    {
        cout << "\nSearch Results:\n------------------\n";
        for(resultIt = vResult.begin(); resultIt != vResult.end(); ++resultIt){
            cout << resultIt->title << setw(8+longest-resultIt->title.length()) << "[NS] " << resultIt->pairType.first << setw(18-resultIt->pairType.first.length()) << "[ID] " << resultIt->pairType.second << endl;
        }
    }
    cout << endl;
}

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
            resultVector.insert(resultVector.end(), wikiEntry(it->first, it->second.pairType.first, it->second.pairType.second));
        }
    }
}

void searchString(vector<wikiEntry> &entries, string userInput, vector<wikiEntry> &resultVector){

    for (auto it : entries) {
        if (it.title.find(toLower(userInput)) != string::npos) {
            resultVector.insert(resultVector.end(), wikiEntry(it.title, it.pairType.first, it.pairType.second));
        }
    }
}

void insertEntry(map<string, wikiEntry> &entries, string title, string ns, string id) {
    entries.insert(pair<string, wikiEntry>(toLower(parseTitle(title)), wikiEntry(title, ns, id)));
}

void insertEntry(map<string, wikiEntry> &entries, string rawData) {
    entries.insert(pair<string, wikiEntry>(toLower(parseTitle(rawData)), wikiEntry(rawData)));
}

void readInData(map<string, wikiEntry> &entries) {
    ifstream file("../../wikiData.dat");
    if(file.fail()) {
        cout << "File failed to load" << endl;
        exit(1);
    }
    else
        cout << "wikiData loaded successfully!" << endl << endl;

    
    // Get input from the file
    wikiData row;
    while (file >> row) {
        insertEntry(entries, row[2], row[0], row[1]);
    }
}

void readInData(vector<wikiEntry> &entries) {
    ifstream file("../../wikiData.dat");
    if(file.fail()) {
        cout << "File failed to load" << endl;
        exit(1);
    }
    else
        cout << "wikiData loaded successfully!" << endl << endl;

    
    // Get input from the file
    wikiData row;
    while (file >> row) {
        // insertEntry(entries, row[2], row[0], row[1]);
        entries.push_back(wikiEntry(toLower(row[2]), row[0], row[1]));
    }
}

void wikiEntry::printEntry()
{
    cout << "Title: " << title << "\nNamespace: " << pairType.first << "\nID: " << pairType.second << endl;
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
