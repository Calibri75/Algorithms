#include <vector>
#include "../struct/struct.h"

using namespace std;

key homo_binarySearch(vector <person>& data, int find_key){
    //Добавление барьеров
    key found_key{};
    int last = data[data.size() - 1].application;
    int first = data[0].application;
    data[0].application = key;
    data[data.size() - 1].application = key;

    //Вычисление степени
    int n = static_cast<int>(data.size());
    int step = n, grade = 0;
    while(step > 1){
        grade += 1;
        step /= 2;
    }

    //Заполнение таблицы
    vector<int> table(grade + 2);

    for(int i = 0; i < grade + 2; i++){
        table[i] = (n + (1 << (i+1)) - 1) / (1 << (i+1));
    }

    //Начальное позиция
    int pos = table[0];
    int i = 0;
    for(i = 0; data[pos].application != find_key; i++){

            if(find_key > data[pos].application) pos += table[i];
            else pos -= table[i];

    }

    //Возвращение значений
    data[0].application = first;
    data[data.size() - 1].application = last;

    if((pos != (data.size() - 1) && pos != 0) || (find_key == last) || (find_key == first)){
        found_key.steps = i + 1;
        found_key.index = data[pos].stroke;
        return found_key;
    }

    return {};
}

//7
//4 2 1 1 0
// 0 1 2 3 4 5 6 7