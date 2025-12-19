#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include "src/structs/structs.h"
#include "src/sorts/sorts.h"
#include "src/file_work/file_work.h"


using namespace std;
using namespace std::chrono;


int main() {
    system("chcp 65001");

    int N = 100000;
    vector<Key> data(N);

    read_file("../LAB2/static/in/input_100000.txt", data, N);
    auto start = high_resolution_clock::now();
    binaries_sort(data, N);
    auto end = high_resolution_clock::now();
    milliseconds duration1 = duration_cast<milliseconds>(end - start);
    write_file("../LAB2/static/out/sort_binaries", data, N, duration1);


    read_file("../LAB2/static/in/input_100000.txt", data, N);
    start = high_resolution_clock::now();
    quick_sort(data, 0, N - 1);
    end = high_resolution_clock::now();
    milliseconds duration2 = duration_cast<milliseconds>(end - start);
    write_file("../LAB2/static/out/sort_quick", data, N, duration2);

    cout << "Quick_sort: " << duration1 << endl;
    cout << "Binaries_sort: " << duration2 << endl;

}

