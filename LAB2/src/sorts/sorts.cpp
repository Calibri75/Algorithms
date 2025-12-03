#include "sorts.h"
#include "../structs/structs.h"
#include <string>
#include <vector>

bool operator<(const Key& a, const Key& b) {
    if (a.date.year != b.date.year)
        return a.date.year < b.date.year;
    if (a.date.month != b.date.month)
        return a.date.month < b.date.month;
    if (a.date.day != b.date.day)
        return a.date.day < b.date.day;

    if (a.fio.F != b.fio.F)
        return a.fio.F > b.fio.F;
    if (a.fio.N != b.fio.N)
        return a.fio.N > b.fio.N;

    return a.fio.O > b.fio.O;
}

bool operator>(const Key& a, const Key& b) {
    return b < a;
}



void quick_sort(vector <Key> &data, int left, int right) {// 6 6 6 6 5 8 3 12 12 12
    if (left < right) {                                //i=-1 j = 5
        int pivot = right, i = left - 1;
        Key temp;
        for (int j = left; j < right; j++) {
            if (data[j] < data[pivot]) {
                i++;
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        temp = data[i + 1];
        data[i + 1] = data[pivot];
        data[pivot] = temp;
        quick_sort(data, left, i);
        quick_sort(data, i + 2, right);
    }

}

void binaries_sort(vector <Key> &data, int n) {
    for (int i = 1; i < n; i++) {
        Key key = data[i];
        int left = 0, right = i - 1;
        while (left <= right) {
            int is_work = 1;
            int mid = (left + right) / 2;
            if (data[i] < data[mid]) right = mid - 1;
            else if (data[i] > data[mid]) left = mid + 1;
            else {
                left = mid;
            }
        }


        for (int j = i - 1; j >= left; j--) {
            data[j + 1] = data[j];
        }

        data[left] = key;

    }
}