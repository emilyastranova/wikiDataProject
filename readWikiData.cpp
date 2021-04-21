#include <iostream>

#include "wikiData.h"

std::istream& operator>>(std::istream& str, wikiData& data) {
    data.readNextRow(str);
    return str;
}
int main() {
    
    std::ifstream file("wikiData.dat");
    
    std::cout << file.fail() << std::endl;

    wikiData row;
    while (file >> row) {
        std::cout << "ns: " << row[0] ; //<< std::endl;
        std::cout << " pageid: " << row[1] ; // << std::endl;
        std::cout << " title: " << row[2] << std::endl;
    }
}