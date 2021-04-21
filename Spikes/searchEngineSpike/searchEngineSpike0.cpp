#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {
    std::vector<int> v1 = {5, 10, 15, 20, 50};
    std::vector<int> v2 = {50, 40, 30, 20, 5};
    std::vector<int> v3 = {1, 2, 20, 4, 5, 50};
    std::set<int> vResult;

    std::ostream_iterator<int> screen(std::cout, " ");

    std::cout << "v1 = ";
    std::copy(v1.begin(), v1.end(), screen);
    std::cout << std::endl;

    std::cout << "v2 = ";
    std::copy(v2.begin(), v2.end(), screen);
    std::cout << std::endl;

    std::cout << "v3 = ";
    std::copy(v3.begin(), v3.end(), screen);
    std::cout << std::endl;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::sort(v3.begin(), v3.end());

    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::inserter(vResult, vResult.begin()));
    std::set_intersection(vResult.begin(), vResult.end(), v3.begin(), v3.end(), std::inserter(vResult, vResult.begin()));
    std::cout << "\nIntersecting values:\n";
    std::copy(vResult.begin(), vResult.end(), screen);

    return 0;
}
