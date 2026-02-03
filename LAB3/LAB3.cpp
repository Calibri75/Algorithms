#include "src/search/search.h"
#include "src/search/barier_search/barrier.hpp"
#include "src/struct/struct.h"
#include "src/file_generation/file_generation.h"
#include "src/file_work/LAB3_file_work.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    system("chcp 65001");
    int n = 100000;
    vector <person> data(n);
    int key_f = 3233;
    generation("../LAB3/static/input/input_file.txt");

    file_read(data, n,"../LAB3/static/input/input_file.txt");

    key found_key = homo_binarySearch(data, key_f);

    key found_key1 = linear_search_barrier(data, key_f);

    write_file(found_key, n, "../LAB3/static/output/output.txt", key_f);
    write_file(found_key1, n, "../LAB3/static/output/output1.txt", key_f);
}