#include "src/search/search.h"
#include "src/struct/struct.h"
#include "src/file_generation/file_generation.h"
#include "src/file_work/LAB3_file_work.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    system("chcp 65001");
    int n = 10;
    vector <person> data(n);
    //generation("../LAB3/static/input/input_file.txt");

    file_read(data, n,"../LAB3/static/input/input_file.txt");

    key found_key = homo_binarySearch(data, 1584);

    write_file(found_key, n, "../LAB3/static/output/output.txt");

}