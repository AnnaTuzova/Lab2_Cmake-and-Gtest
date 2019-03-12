#include "Sort_lib.h"

void SelectionSort(int *data, const int kNumOfElements)
{

	for (int i = 0; i < kNumOfElements - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < kNumOfElements; j++)
		{
			if (data[min_index] > data[j])
			{
				min_index = j;
			}

		}

		if (min_index != i)
		{
			std::swap(data[i], data[min_index]);
		}
	}
}