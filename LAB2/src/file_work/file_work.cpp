#include "file_work.h"
#include "../structs/structs.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


bool read_file(const string& filename, vector <Key>& data, int N){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Не удалось открыть файл " << filename << endl;
        return false;
    }

    for(int i = 0; i < N; i++){
        file >> data[i].date.day >> data[i].date.month >> data[i].date.year >> data[i].fio.F >> data[i].fio.N >> data[i].fio.O;
        data[i].num_str = i;
    }
    return true;
}

bool write_file(const string& filename, vector <Key>& data, int N, milliseconds duration){
    ofstream file(filename);

    if(!file.is_open()){
        cout << "Не удалось открыть файл " << filename << endl;
        return false;
    }

    for(int i = 0; i < N; i++){
        file << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " " << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << " " << data[i].num_str << endl;
    }

    file << duration;
    return true;
}

