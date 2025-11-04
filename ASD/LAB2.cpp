#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;
using namespace std::chrono;

struct Fio{
    string F;
    string N;
    string O;
};

struct Date{
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
void print(Key* data, int N){
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " "
             << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << "\n";
    }
}

void binaries_sort_date(Key* data, int N){
    for (int i = 1; i < N; i++) {
        Key key = data[i];
        int left = 0, right = i - 1;
        while(left <= right){       //[1] left -> [2] <- right [3] [4]
            int mid = (right + left) / 2;
            if(data[i].date.year > data[mid].date.year)left = mid + 1; // 0 1 2 3 4 5 6 7 8
            else if(data[i].date.year < data[mid].date.year) right = mid - 1;
            else{
                if(data[i].date.month > data[mid].date.month)left = mid + 1;
                else if(data[i].date.month < data[mid].date.month)right = mid - 1;

                else{
                    if(data[i].date.day > data[mid].date.day)left = mid + 1;
                    else if(data[i].date.day < data[mid].date.day)right = mid - 1;

                    else{
                        left = mid;
                        break;
                    }
                }
            }
        }

        for(int j = i - 1; j >= left; j--){
            data[j + 1] = data[j];
        }

        data[left] = key;

    }

}

void binaries_sort_fio(Key* data, int N){
    for (int i = 1; i < N; i++) {
        Key key = data[i];
        int left = 0, right = i - 1, f = 0, n = 0, o = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if(f < data[i].fio.F.length() or f < data[mid].fio.F.length()) {
                if (data[i].fio.F[f] < data[mid].fio.F[f])left = mid + 1;
                else if (data[i].fio.F[f] > data[mid].fio.F[f])right = mid - 1;
                else f++;
            }
            else if(n < data[i].fio.N.length() or n < data[mid].fio.N.length()) {
                if (data[i].fio.N[n] < data[mid].fio.N[n])left = mid + 1;
                else if (data[i].fio.N[n] > data[mid].fio.N[n])right = mid - 1;
                else n++;
            }
            else if(o < data[i].fio.O.length() or o < data[mid].fio.O.length()) {
                if (data[i].fio.O[o] < data[mid].fio.O[o])left = mid + 1;
                else if (data[i].fio.O[o] > data[mid].fio.O[o])right = mid - 1;
                else o++;
            }
            else{
                left = mid;
                break;
            }
        }

        for(int j = i - 1; j >= left; j--){
            data[j + 1] = data[j];
        }

        data[left] = key;
    }
}

void binaries_sort_fio_test(Key* data, int N) {
    for (int i = 1; i < N; i++) {
        Key key = data[i];
        int left = 0, right = i - 1, f = 0, n = 0, o = 0;
        while (left <= right) {
            cout << "индекс элемента - " << i << "\nИндекс буквы Фамилии - " << f
                 << "\nИндекс буквы Имени - " << n << "\nИндекс буквы Отчества - " << o << endl;
            for (int c = 0; c < data[i].fio.F.length(); c++) {
                cout << data[i].fio.F[c];
            }
            cout << endl;
            int mid = (left + right) / 2;
            if (f < data[i].fio.F.length() or f < data[mid].fio.F.length()) {
                if (data[i].fio.F[f] > data[mid].fio.F[f]) {
                    left = mid + 1;
                    cout << "+\n";
                } else if (data[i].fio.F[f] < data[mid].fio.F[f]) {
                    right = mid - 1;
                    cout << "-\n";
                } else {
                    cout << "else f\n";
                    f++;
                }
            } else if (n < data[i].fio.N.length() or n < data[mid].fio.N.length()) {
                if (data[i].fio.N[n] > data[mid].fio.N[n])left = mid + 1;
                else if (data[i].fio.N[n] < data[mid].fio.N[n])right = mid - 1;
                else {
                    cout << "else n\n";
                    n++;
                }
            } else if (o < data[i].fio.O.length() or o < data[mid].fio.O.length()) {
                if (data[i].fio.O[o] > data[mid].fio.O[o])left = mid + 1;
                else if (data[i].fio.O[o] < data[mid].fio.O[o])right = mid - 1;
                else {
                    cout << "else o\n";
                    o++;
                }
            } else {
                left = mid;
                break;
            }
        }

        for (int j = i - 1; j >= left; j--) {
            data[j + 1] = data[j];
        }

        data[left] = key;
        cout << "Меж итог: \n";
        print(data, N);
    }
}

void quick_sort_date(Key* data, int left, int right){// 6 6 6 6 5 8 3 12 12 12
    if(left < right){                                //i=-1 j = 5
        int pivot = right, i = left - 1;
        for(int j = left; j < right; j++){
            if(data[j].date.year < data[pivot].date.year){
                i++;
                swap(data[i], data[j]);
            }
            else if(data[j].date.year == data[pivot].date.year){
                if(data[j].date.month < data[pivot].date.month){
                    i++;
                    swap(data[i], data[j]);
                }
                else if (data[j].date.month == data[pivot].date.month){
                    if(data[j].date.day <= data[pivot].date.day){
                        i++;
                        swap(data[i], data[j]);
                    }
                }
            }
        }
        swap(data[i+1], data[pivot]);
        quick_sort_date(data, left, i);
        quick_sort_date(data, i + 2, right);
    }
}

void quick_sort_fio(Key* data, int left, int right){
    if(left < right){
        int pivot = right, i = left - 1;
        for(int j = left; j < right; j++){
            if(data[j].fio.F > data[pivot].fio.F){
                i++;
                swap(data[i], data[j]);
            }
            else if(data[j].fio.F == data[pivot].fio.F){
                if(data[j].fio.N > data[pivot].fio.N){
                    i++;
                    swap(data[i], data[j]);
                }
                else if(data[j].fio.N == data[pivot].fio.N){
                    if(data[j].fio.O >= data[pivot].fio.O){
                        i++;
                        swap(data[i], data[j]);
                    }
                }
            }
        }
        swap(data[i+1], data[pivot]);
        quick_sort_fio(data, left, i);
        quick_sort_fio(data, i + 2, right);
    }
}




int main(){
    system("chcp 65001");

    int N = 10000;
    Key* data = new Key[N];
    ifstream file("input_data1.txt");
    //формат 17 04 06 z b a
   /* for (int i = 0; i < N; i++) {
        file >> data[i].date.day >> data[i].date.month >> data[i].date.year >> data[i].fio.F >> data[i].fio.N >> data[i].fio.O;
    }*/
   //Формат 17.04.06 z b a
    string line;
    for (int i = 0; i < N; i++){
        string part;
        getline(file, line);
        stringstream l(line);

        getline(l, part, '.');
        data[i].date.day = stoi(part);

        getline(l, part, '.');
        data[i].date.month = stoi(part);

        getline(l, part, ' ');
        data[i].date.year = stoi(part);

        l >> data[i].fio.F >> data[i].fio.N >> data[i].fio.O;

        data[i].num_str = i;
    }
    file.close();

    //ВЫВОД БИНАРНЫХ СТАВОК В ФАЙЛ
    ofstream out_file_bin("out_data_binaries");
    auto start = high_resolution_clock::now();
    binaries_sort_date(data, N);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    out_file_bin << "СОРТИРОВКА ПО ДАТЕ\n";
    for(int i = 0; i < N; i++){
        out_file_bin << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " "
        << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << " " << data[i].num_str << endl;
    }
    out_file_bin << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;

    start = high_resolution_clock::now();
    binaries_sort_fio(data, N);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_bin << "CОРТИРОВКА ПО ФИО\n";
    for(int i = 0; i < N; i++){
        out_file_bin << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " "
                 << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << " " << data[i].num_str << endl;
    }
    out_file_bin << "Время, затраченное на сортировку: " << duration.count() << " мс";
    out_file_bin.close();

    //ВЫВОД БЫСТРОЙ СОРТИРОВКИ В ФАЙЛ
    ofstream out_file_quick("out_data_quick");
    start = high_resolution_clock::now();
    quick_sort_date(data, 0, N - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_quick << "CОРТИРОВКА ПО ДАТЕ\n";
    for(int i = 0; i < N; i++){
        out_file_quick << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " "
                       << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << " " << data[i].num_str << endl;
    }
    out_file_quick << "Время, затраченное на сортировку: " << duration.count() << " мс" << endl;

    start = high_resolution_clock::now();
    quick_sort_fio(data, 0, N - 1);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    out_file_quick << "CОРТИРОВКА ПО ФИО\n";
    for(int i = 0; i < N; i++){
        out_file_quick << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " "
                       << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << " " << data[i].num_str << endl;
    }
    out_file_quick << "Время, затраченное на сортировку: " << duration.count() << " мс";
    out_file_quick.close();

    delete[] data;

}

