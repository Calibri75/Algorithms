#include "../../struct/struct.h"
#include <vector>
#include <string>
#include <iostream>

vector<int> build_lps(const string &pattern) {
    int pattern_length = static_cast<int>(pattern.length());
    vector<int> lps(pattern_length, 0);

    int len = 0; // длина префиска
    int i = 1;

    while (i < pattern_length) {//aba
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool kmp_exact_count(const string &text, const string &pattern, int requiredCount) {
    int n = static_cast<int>(text.length());
    int m = static_cast<int>(pattern.length());

    if (n < m)
        return false;

    vector<int> lps = build_lps(pattern);


    int i = 0;
    int j = 0;
    int foundCount = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            foundCount++;


            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return foundCount;
}

vector<int> kmp_search_persons(const vector<person> &data, const vector<string> &pattern_m, int requiredCount) {
    vector<int> result(data.size());
    int k = 0;
    int flag = 0;

    for (const person &p : data) {

        string fioStr = p.fio.surname + " " + p.fio.name + " " + p.fio.patronymic;

        for (const string &pattern : pattern_m) {

            int fioMatch;
            int descMatch;


            fioMatch = kmp_exact_count(fioStr, pattern, requiredCount);

            if(fioMatch != requiredCount){
                descMatch = kmp_exact_count(p.description, pattern, requiredCount);
                fioMatch += descMatch;
            }

            if (fioMatch >= requiredCount) {
                result[k] = p.stroke;
                flag = 1;
                ++k;
            }
        }
    }

    if (flag == 0) {
        result[0] = -1;
        result.resize(1);
        return result;
    }

    result.resize(k);
    return result;
}