#include <vector>
#include "../struct/struct.h"


person homo_binarySearch(const vector <person>& data, int key){
    int n = data.size();

    int step = 1;
    while(step < n) step <<= 1;
    step >>= 1;

    int delta = 0;
    int next_step = step;
    while(step > 0){
        delta = step - next_step;
        int i = step + delta;
        if(key <= data[i - 1].application){
            if(key == data[i - 1].application) return data[i - 1];
            step >>= 1;
            next_step = step;
        }
        next_step >>= 1;
    }

    return{};
}