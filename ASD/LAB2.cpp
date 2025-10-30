#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Fio{
    string F;
    string N;
    string O;

    Fio() : F(""), N(""), O("") {}
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
                        left = right;
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

    for (int i = 1; i < N; i++) {
        string alh = data[1].fio.F + data[1].fio.N + data[1].fio.O;//цельная строка для переьбора по буквам
        Key key = data[i];
        int left = 0, right = i - 1, j = 0;;
        while(left <= right){
            int mid = (left + right) / 2;
            string alh_mid = data[mid].fio.F + data[mid].fio.N + data[mid].fio.O;
            if(j <= alh.length() and j <= ){//Если 1 фамилия закончится быстрее второй?
                if(alh[j] < data[mid].fio.F[j]) right = mid - 1;
                else if (data[i].fio.F[j] > data[mid].fio.F[j]) left = mid +  1;
                else{
                    j++;
                }

            }
        }
    }
}

int main(){
    system("chcp 65001");
    int N = 7;
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
    sort_binaries(data, N);
    cout << "После сортировки:\n";
    print(data, N);


    file.close();
    delete[] data;

}

