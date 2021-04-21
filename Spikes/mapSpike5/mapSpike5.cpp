#include <algorithm>  // std::sort
#include <iostream>
#include <iterator>  // std::back_inserter
#include <map>
#include <utility>  // std::pair
#include <vector>

using namespace std;

bool comp(const std::pair<string, string> &lhs, const std::pair<string, string> &rhs) {
    // Check first column
    // Check second column
    return lhs.first < rhs.first;
    // } else if (lhs.first == rhs.first ){
    //     return (lhs.second < rhs.second);
    // } else {
    //     return (lhs.second >= rhs.second);
    // }
}
bool compSecond(const std::pair<string, string> &lhs, const std::pair<string, string> &rhs) {
    // Check first column
    // Check second column
    return (lhs.first == rhs.first) && (lhs.second < rhs.second);

    // } else if (lhs.first == rhs.first ){
    //     return (lhs.second < rhs.second);
    // } else {
    //     return (lhs.second >= rhs.second);
    // }
}

int main() {
    std::vector<std::pair<string, string>> v1;
    std::vector<std::pair<string, string>> v2;

    v1.push_back(pair<string, string>("101", "201"));
    v1.push_back(pair<string, string>("102", "203"));
    v1.push_back(pair<string, string>("101", "202"));
    v1.push_back(pair<string, string>("401", "204"));

    v2.push_back(pair<string, string>("201", "422"));
    v2.push_back(pair<string, string>("201", "402"));
    v2.push_back(pair<string, string>("101", "202"));
    v2.push_back(pair<string, string>("202", "402"));
    v2.push_back(pair<string, string>("401", "204"));


    std::sort(v1.begin(), v1.end(), comp);
    std::sort(v2.begin(), v2.end(), comp);
    std::sort(v2.begin(), v2.end(), compSecond);

    vector<std::pair<std::string, std::string>>::iterator ptr = v1.begin();
    for (ptr = v1.begin(); ptr < v1.end(); ptr++) {
        cout << '<' << ptr->first << " " << ptr->second << '>';
    }
    cout << endl;

    vector<std::pair<std::string, std::string>>::iterator ptr2 = v2.begin();
    for (ptr2 = v2.begin(); ptr2 < v2.end(); ptr2++) {
        cout << '<' << ptr2->first << " " << ptr2->second << '>';
    }
    cout << endl;

    // std::vector<std::pair<string, string>> result;
    // std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
    // std::back_inserter(result), comp );

    // // Displaying vector elements using begin() and end()
    // vector<std::pair<std::string, std::string>>::iterator ptr =
    // result.begin(); for (ptr = result.begin(); ptr < result.end(); ptr++) {
    //     cout << '<' << ptr->first << " " << ptr->second << '>';
    // }
    // cout << endl;

    return 0;
}