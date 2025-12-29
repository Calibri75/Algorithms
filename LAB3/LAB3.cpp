#include "src/search/search.h"
#include "src/struct/struct.h"
#include "src/file_generation/file_generation.h"
#include "src/file_work/LAB3_file_work.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n = 1000;
    vector <person> data(n);
    generation("../LAB3/static/output/input_file.txt");

    file_read(data, n,"input_file");

    key found_key = homo_binarySearch(data, 2);

    write_file(found_key, n, "output.txt");

}