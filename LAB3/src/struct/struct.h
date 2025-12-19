#ifndef ASD_STRUCT_H
#define ASD_STRUCT_H

#include <string>

using namespace std;

struct key{
    int index;
    int steps;
};

struct FIO{
    string name;
    string surname;
    string patronymic;
};

struct DATE{
    int day;
    int month;
    int year;
};

struct person{
    FIO fio;
    DATE date;
    int application{};
};

#endif //ASD_STRUCT_H
