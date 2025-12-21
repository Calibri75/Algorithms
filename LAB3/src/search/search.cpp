#include <vector>
#include "../struct/struct.h"


person homo_binarySearch(const vector <person>& data, int key){
    size_t n = data.size();
    int m[] = {2, 4, 8, 16};
    int step = 1;
    while(step < n) step <<= 1;
    step >>= 1;

    int pos = -1;

    while(step > 0){
        if(pos + step < n && data[step + pos] < key){
            pos += step;
        }
        step >>= 1;
    }

    return{};
}