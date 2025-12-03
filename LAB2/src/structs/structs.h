#include <string>
using namespace std;

#ifndef ASD_STRUCTS_H
#define ASD_STRUCTS_H



struct Fio {
    string F;
    string N;
    string O;
};

struct Date {
    int day;
    int month;
    int year;

    Date() : day(0), month(0), year(0) {}
};

struct Key {
    Date date;
    Fio fio;
    int num_str;
};



#endif //ASD_STRUCTS_H
