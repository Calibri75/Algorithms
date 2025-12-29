#ifndef ASD_FILE_WORK_HPP
#define ASD_FILE_WORK_HPP

#include <vector>
#include <string>
#include "../struct/struct.h"

using namespace std;

bool file_read(vector <person>& data, int n, const string& filename);

bool write_file(key found_key, int n, const string& filename);

#endif //ASD_FILE_WORK_HPP
