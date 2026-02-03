#ifndef ASD_SEARCH_HPP
#define ASD_SEARCH_HPP

#include <vector>
#include "../../struct/struct.h"
#include <string>

using namespace std;

vector<int> kmp_search_persons(const vector<person> &data, const vector<string> &pattern_m, int requiredCount);
vector<int> build_lps(const string &pattern);

#endif //ASD_SEARCH_HPP
