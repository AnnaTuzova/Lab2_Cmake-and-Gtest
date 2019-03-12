#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

extern "C" {
	__declspec(dllexport) void SelectionSort(int *data, const int kNumOfElements);
}