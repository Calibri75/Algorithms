#include "sorts.h"
#include "../structs/structs.h"
#include <string>
#include <vector>

void quick_sort(vector <Key> &data, int left, int right) {// 6 6 6 6 5 8 3 12 12 12
    if (left < right) {                                //i=-1 j = 5
        int pivot = right, i = left - 1, temp;
        string s_temp;
        for (int j = left; j < right; j++) {
            int sort = 1;
            if (data[j].date.year < data[pivot].date.year) {
                i++;
                temp = data[i].date.year;
                data[i].date.year = data[j].date.year;
                data[j].date.year = temp;
            } else if (data[j].date.year == data[pivot].date.year) {
                if (data[j].date.month < data[pivot].date.month) {
                    i++;
                    temp = data[i].date.month;
                    data[i].date.month = data[j].date.month;
                    data[j].date.month = temp;
                } else if (data[j].date.month == data[pivot].date.month) {
                    if (data[j].date.day < data[pivot].date.day) {
                        i++;
                        temp = data[i].date.day;
                        data[i].date.day = data[j].date.day;
                        data[j].date.day = temp;
                    } else {
                        sort = 0;
                    }
                }
            }


            if (!sort) {
                if (data[j].fio.F > data[pivot].fio.F) {
                    i++;
                    s_temp = data[i].fio.F;
                    data[j].fio.F = data[i].fio.F;
                    data[j].fio.F = s_temp;
                } else if (data[j].fio.F == data[pivot].fio.F) {
                    if (data[j].fio.N > data[pivot].fio.N) {
                        i++;
                        s_temp = data[i].fio.N;
                        data[j].fio.N = data[i].fio.N;
                        data[j].fio.N = s_temp;
                    } else if (data[j].fio.N == data[pivot].fio.N) {
                        if (data[j].fio.O >= data[pivot].fio.O) {
                            i++;
                            s_temp = data[i].fio.O;
                            data[j].fio.O = data[i].fio.O;
                            data[j].fio.O = s_temp;
                        }
                    }
                }
            }
        }
        swap(data[i + 1], data[pivot]);
        quick_sort(data, left, i);
        quick_sort(data, i + 2, right);
    }

}

void binaries_sort(vector <Key> &data, int n) {
    for (int i = 1; i < n; i++) {
        Key key = data[i];
        int left = 0, right = i - 1;
        while (left < right) {
            int is_work = 1;
            int mid = (left + right) / 2;
            if (data[i].date.year < data[mid].date.year) right = mid - 1;
            else if (data[i].date.year > data[mid].date.year) left = mid + 1;
            else {
                if (data[i].date.month < data[mid].date.month) right = mid - 1;
                else if (data[i].date.month > data[mid].date.month) left = mid + 1;
                else {
                    if (data[i].date.month < data[mid].date.month) right = mid - 1;
                    else if (data[i].date.month > data[mid].date.month) left = mid + 1;
                    else {
                        is_work = 0;
                    }
                }
            }

            if (!is_work) {

                if (data[i].fio.F < data[mid].fio.F)left = mid + 1;
                else if (data[i].fio.F > data[mid].fio.F)right = mid - 1;
                else {
                    if (data[i].fio.N < data[mid].fio.N)left = mid + 1;
                    else if (data[i].fio.N > data[mid].fio.N)right = mid - 1;
                    else {
                        if (data[i].fio.O < data[mid].fio.O)left = mid + 1;
                        else if (data[i].fio.O > data[mid].fio.O)right = mid - 1;
                        else {
                            left = mid;
                            break;
                        }
                    }
                }
            }
        }
        for (int j = right; j >= left; j--) {
            data[j + 1] = data[j];
        }

        data[left] = key;

    }
}