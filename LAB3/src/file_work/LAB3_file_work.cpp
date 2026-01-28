#include "LAB3_file_work.h"
#include "../struct/struct.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

bool file_read(vector <person>& data, int n, const string& filename){
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Не удалось открыть файл\n";
        return false;
    }

    for(int i = 0; i < n; i++){
        file >> data[i].date.day >> data[i].date.month >> data[i].date.year
        >> data[i].fio.surname >> data[i].fio.name >> data[i].fio.patronymic >> data[i].application;
        data[i].stroke = i;
    }
    return true;
}

bool write_file(key found_key, int n, const string& filename){
    ofstream file(filename);

    if(!file.is_open()){
        cout << "Не удалось открыть файл\n";
        return false;
    }

    file << "Индекс: " << found_key.index << endl;
    file << "Количество шагов: " << found_key.steps << endl;

    return true;
}