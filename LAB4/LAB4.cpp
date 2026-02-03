#include "src/search/BMX/BMX.hpp"
#include "src/struct/struct.h"
#include "src/file_generation/file_generation.h"
#include "src/file_work/LAB4_file_work.h"
#include "src/search/BMX/BMX.hpp"
#include "src/search/KMP/KMP.h"
#include <iostream>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main(){
    system("chcp 65001");
    int n = 10;
    vector <person> data(n);
    vector <int> id(n);
    vector<string> pattern = {"m"};

    generation("../LAB4/static/input/input_file.txt");
    file_read(data, n, "../LAB4/static/input/input_file1.txt");

    auto start = high_resolution_clock::now();
    id = bmh_search_persons(data, pattern, 2);
    auto end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);
    write_file(data, id, n, "../LAB4/static/output/output_BMH.txt", duration);

    start = high_resolution_clock::now();
    id = kmp_search_persons(data, pattern, 2);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    write_file(data, id, n, "../LAB4/static/output/output_KMP.txt", duration);
}