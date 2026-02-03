#include "file_generation.h"
#include <random>
#include <fstream>
#include <string>
#include <cctype>


using namespace std;


void generation(const string& filename){
    string alpha_vowels = "aeiouy";
    string alpha_consonants = "bcdfghjklmnpqrstvwxz";
    ofstream file(filename);

    random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist_day(1, 31);
    uniform_int_distribution<> dist_month(1, 12);
    uniform_int_distribution<> dist_year(1980, 2025);
    uniform_int_distribution<> dist_vowels(0, static_cast<int>(alpha_vowels.size() - 1));
    uniform_int_distribution<> dist_consonants(0, static_cast<int>(alpha_consonants.size() - 1));
    uniform_int_distribution<> dist_long(5, 12);
    uniform_int_distribution<> dist_application(0, 5000);

    for(int i = 0; i < 1000000; i++){
        string name, surname, patronymic;
        for(int j = 0; j < dist_long(gen); j++){
            if(j % 2 == 0) {
                name += alpha_consonants[dist_consonants(gen)];
                surname += alpha_consonants[dist_consonants(gen)];
                patronymic += alpha_consonants[dist_consonants(gen)];
            }
            else {
                name += alpha_vowels[dist_vowels(gen)];
                surname += alpha_vowels[dist_vowels(gen)];
                patronymic += alpha_vowels[dist_vowels(gen)];
            }
        }

        name[0] = static_cast<char>(toupper(static_cast<unsigned char>(name[0])));
        surname[0] = static_cast<char>(toupper(static_cast<unsigned char>(surname[0])));
        patronymic[0] = static_cast<char>(toupper(static_cast<unsigned char>(patronymic[0])));

        file << dist_day(gen) << " " << dist_month(gen) << " " << dist_year(gen) << " "
        << name << " " << surname << " " << patronymic << " " << i << " " << "\n";

    }
}