#include <iostream>
#include "src/search/search.hpp"
#include "src/struct/struct.h"

int main(){
    vector <person> data;
    person a = {{"z", "v", "a"}, {1, 2 ,3}, 1};
    person b = {{"f", "v", "a"}, {1, 2 ,3}, 2};
    person c = {{"g", "v", "a"}, {1, 2 ,3}, 3};
    data.push_back(a);
    data.push_back(b);
    data.push_back(c);

    person i = homo_binarySearch(data, 2);
    cout << i.fio.name;
}