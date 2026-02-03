#include "../../struct/struct.h"
#include <vector>

key linear_search_barrier(vector<person>& data, int find_key){
    key found_key{};

    int n = static_cast<int>(data.size());
    if(n == 0){
        found_key.index = -1;
        found_key.steps = -1;
        return found_key;
    }

    person last = data[n - 1];
    data[n - 1].application = find_key;

    int i = 0;
    while(data[i].application != find_key){
        i++;
        found_key.steps++;
    }

    data[n - 1] = last;

    if(i < n - 1 || last.application == find_key){
        found_key.index = data[i].stroke;
    } else {
        found_key.index = -1;
        found_key.steps = -1;
    }

    return found_key;
}