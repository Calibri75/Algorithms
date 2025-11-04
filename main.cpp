#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Генерация случайного слова (латиница)
string makeWord(int minLen, int maxLen) {
    static const string letters = "abcdefghijklmnopqrstuvwxyz";
    int len = minLen + rand() % (maxLen - minLen + 1);
    string w;
    w.reserve(len);
    for (int i = 0; i < len; ++i)
        w += letters[rand() % letters.size()];
    w[0] = toupper(w[0]);
    return w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(static_cast<unsigned>(time(0)));

    ofstream file("people.txt", ios::out | ios::trunc);
    if (!file.is_open()) {
        cerr << "Error opening file!\n";
        return 1;
    }

    const int N = 1000000;
    string buffer;
    buffer.reserve(10'000'000); // заранее выделяем память под буфер

    for (int i = 1; i <= N; ++i) {
        int day = rand() % 28 + 1;
        int month = rand() % 12 + 1;
        int year = 2000 + rand() % 26;

        // Формируем строку
        buffer += (day < 10 ? "0" : "") + to_string(day) + "."
                  + (month < 10 ? "0" : "") + to_string(month) + "."
                  + to_string(year) + " "
                  + makeWord(5, 9) + " "
                  + makeWord(4, 8) + " "
                  + makeWord(6, 10) + "\n";

        // Сбрасываем буфер каждые 100 000 строк
        if (i % 100000 == 0) {
            file << buffer;
            buffer.clear();
        }
    }

    // Финальный сброс, если остались данные
    if (!buffer.empty())
        file << buffer;

    file.flush(); // гарантированная запись на диск
    file.close();

    cout << "✅ Файл people.txt успешно создан (1 000 000 строк)\n";
}
