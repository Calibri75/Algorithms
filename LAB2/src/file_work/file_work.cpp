#include "file_work.h"
#include "../structs/structs.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


bool read_file(const string& filename, vector <Key>& data, int N){
    ifstream file(filename);

    for(int i = 0; i < N; i++){
        file >> data[i].date.day >> data[i].date.month >> data[i].date.year >> data[i].fio.F >> data[i].fio.N >> data[i].fio.O;
    }
}

