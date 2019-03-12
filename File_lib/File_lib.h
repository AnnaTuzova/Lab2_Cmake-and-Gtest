#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void FillingFile(const int kNumOfElements, const char* kPath);
void ReadingFile(int *data, const int kNumOfElements, const char* kPath);
void WritingFile(int *sorted_data, const int kNumOfElements, const char* kPath);