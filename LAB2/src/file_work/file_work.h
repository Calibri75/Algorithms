#ifndef ASD_FILE_WORK_H
#define ASD_FILE_WORK_H
#include "../sorts/sorts.h"
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

bool read_file(const string& filename, vector <Key>& data, int N);
bool write_file(const string& filename, vector <Key>& data, int N, milliseconds duration);

#endif //ASD_FILE_WORK_H
