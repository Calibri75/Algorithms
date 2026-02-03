    #include <vector>
    #include "../struct/struct.h"

    using namespace std;

    key homo_binarySearch(vector <person>& data, int find_key){
        key found_key{};
        int flag = 0;

        //Вычисление степени
        int n = static_cast<int>(data.size());
        int grade = (n == 0)? -1: 63 - __builtin_clzll(n);

        //Заполнение таблицы
        vector<long long> table(grade + 2);

        for(int i = 0; i < grade + 2; i++){
            table[i] = (n + (1 << (i))) / (1 << (i+1));
        }

        //Начальное позиция
        long long pos = table[0] - 1;

        for(int i = 1; i < table.size(); i++){

                if(find_key == data[pos].application) {
                    flag = 1;
                    found_key.steps = i;
                    found_key.index = data[pos].stroke;
                    break;
                }
                else if(find_key > data[pos].application) pos = pos + table[i];
                else pos = pos - table[i];

        }

        if(flag == 0){
            found_key.steps = -1;
            found_key.index = -1;
        }
        return found_key;
    }