#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

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
};

void print(Key* data, int N){
    for (int i = 0; i < N; i++) {
        cout << i + 1 << ". " << data[i].date.day << "." << data[i].date.month << "." << data[i].date.year << " "
             << data[i].fio.F << " " << data[i].fio.N << " " << data[i].fio.O << "\n";
    }
}

void sort_binaries(Key* data, int N){
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
                        left = right - 1;
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

void sort_binaries_fio(Key* data, int N){
    for (int i = 1; i < N; i++) {
        Key key = data[i];
        int left = 0, right = i - 1, f = 0, n = 0, o = 0;
        while(left <= right){
            cout << endl;
            int mid = (left + right) / 2;
            if(f < data[i].fio.F.length() or f < data[mid].fio.F.length()) {
                if (data[i].fio.F[f] > data[mid].fio.F[f])left = mid + 1;
                else if (data[i].fio.F[f] < data[mid].fio.F[f])right = mid - 1;
                else f++;
            }
            else if(n < data[i].fio.N.length() or n < data[mid].fio.N.length()) {
                if (data[i].fio.N[n] > data[mid].fio.N[n])left = mid + 1;
                else if (data[i].fio.N[n] < data[mid].fio.N[n])right = mid - 1;
                else n++;
            }
            else if(o < data[i].fio.O.length() or o < data[mid].fio.O.length()) {
                if (data[i].fio.O[o] > data[mid].fio.O[o])left = mid + 1;
                else if (data[i].fio.O[o] < data[mid].fio.O[o])right = mid - 1;
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
        print(data, N);
    }
}

void test_sort_binaries_fio(Key* data, int N){
    for (int i = 1; i < N; i++) {
        Key key = data[i];
        int left = 0, right = i - 1, f = 0, n = 0, o = 0;
        while(left <= right){
            cout << "индекс элемента - " << i << "\nИндекс буквы Фамилии - " << f
                 << "\nИндекс буквы Имени - " << n << "\nИндекс буквы Отчества - " << o << endl;
            for (int c = 0; c < data[i].fio.F.length(); c++) {
                cout << data[i].fio.F[c];
            }
            cout << endl;
            int mid = (left + right) / 2;
            if(f < data[i].fio.F.length() or f < data[mid].fio.F.length()) {
                if (data[i].fio.F[f] > data[mid].fio.F[f]) {
                    left = mid + 1;
                    cout << "+\n";
                }
                else if (data[i].fio.F[f] < data[mid].fio.F[f]) {
                    right = mid - 1;
                    cout << "-\n";
                }
                else {
                    cout << "else f\n";
                    f++;
                }
            }
            else if(n < data[i].fio.N.length() or n < data[mid].fio.N.length()) {
                if (data[i].fio.N[n] > data[mid].fio.N[n])left = mid + 1;
                else if (data[i].fio.N[n] < data[mid].fio.N[n])right = mid - 1;
                else {
                    cout << "else n\n";
                    n++;
                }
            }
            else if(o < data[i].fio.O.length() or o < data[mid].fio.O.length()) {
                if (data[i].fio.O[o] > data[mid].fio.O[o])left = mid + 1;
                else if (data[i].fio.O[o] < data[mid].fio.O[o])right = mid - 1;
                else {
                    cout << "else o\n";
                    o++;
                }
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
        cout << "Меж итог: \n";
        print(data, N);
    }
}


int main(){
    system("chcp 65001");
    int N = 10;
    Key* data = new Key[N];
    ifstream file("input_data1");
   /* for (int i = 0; i < N; i++) {
        file >> data[i].date.day >> data[i].date.month >> data[i].date.year >> data[i].fio.F >> data[i].fio.N >> data[i].fio.O;
    }*/
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
    }


    cout << "До сортировки:\n";
    print(data, N);
    sort_binaries_fio(data, N);
    cout << "После сортировки:\n";
    print(data, N);


    file.close();
    delete[] data;

}

