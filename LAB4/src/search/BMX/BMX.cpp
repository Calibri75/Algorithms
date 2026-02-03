#include "../../struct/struct.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;



int bmh_exact_count(const std::string& text, const std::string& pattern, int requiredCount) {

    int pattern_length = static_cast<int>(pattern.length());
    int text_length = static_cast<int>(text.length());

    if (text_length < pattern_length)
        return false;

    int skip[256];

    for (int & c : skip)
        c = pattern_length;

    for (int i = 0; i < pattern_length - 1; ++i)
        skip[(unsigned char)pattern[i]] = pattern_length - 1 - i;

    int start_position_pattern = 0;
    int foundCount = 0;

    while (start_position_pattern <= text_length - pattern_length) {
        int j = pattern_length - 1;

        while (j >= 0) {
            if (text[start_position_pattern + j] == pattern[j])
                --j;
            else
                break;
        }

        if (j < 0) {
            foundCount++;

            start_position_pattern += 1;
        }
        else {
            start_position_pattern += skip[(unsigned char)text[start_position_pattern + pattern_length - 1]];
        }
    }

    return foundCount;
}

vector<int> bmh_search_persons(const vector<person>& data, const vector<string>& pattern_m, int requiredCount) {
    vector<int> result(data.size());
    int k = 0;
    int flag = 0;

    for (const person& p : data) {

        string fio_str = p.fio.surname + " " + p.fio.name + " " + p.fio.patronymic;

        for(const string& pattern : pattern_m){

            int fioMatch;
            int descMatch;


            fioMatch = bmh_exact_count(fio_str, pattern, requiredCount);

            if(fioMatch != requiredCount){
                descMatch = bmh_exact_count(p.description, pattern, requiredCount);
                fioMatch += descMatch;
            }

            if (fioMatch >= requiredCount) {
                result[k] = p.stroke;
                flag = 1;
                ++k;
            }
        }
    }
    if(flag == 0){
        k = 1;
        result[0] = -1;
    }
    result.resize(k);

    return result;
}




