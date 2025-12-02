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

    int N = 4;
    auto start, end;
    vector<Key> data(N);

    read_file("data.txt", data, N);

    start = high_resolution_clock::now();
    binaries_sort(data, N);
    end = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(end - start);


    start = high_resolution_clock::now();
    quick_sort(data, 0, N - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

}

