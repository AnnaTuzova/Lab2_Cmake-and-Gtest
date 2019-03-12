#include "../File_lib/File_lib.h"
#include <windows.h>
#include <gtest/gtest.h>

const int kNumOfElements = 100;

void DllSelectionSort(int *data, const int kNumOfElements);

TEST(TestSort, TestRanomdArray)
{
	int *expected_array = new int[kNumOfElements];
	int *actual_array = new int[kNumOfElements];

	std::srand(time(0));
	for (int i = 0; i < kNumOfElements; i++)
	{
		expected_array[i] = std::rand() % 1000;
	}

	std::copy(expected_array, expected_array + kNumOfElements, actual_array);
	std::sort(expected_array, expected_array + kNumOfElements);

	DllSelectionSort(actual_array, kNumOfElements);
	
	for (int i = 0; i < kNumOfElements; i++)
	{
		ASSERT_EQ(expected_array[i], actual_array[i]);
	}

	delete[] actual_array, expected_array;
}

TEST(TestSort, TestSortedArray)
{
	int *expected_array = new int[kNumOfElements];
	int *actual_array = new int[kNumOfElements];

	for (int i = 0; i < kNumOfElements; i++)
	{
		expected_array[i] = i;
	}
	std::copy(expected_array, expected_array + kNumOfElements, actual_array);

	DllSelectionSort(actual_array, kNumOfElements);
	
	for (int i = 0; i < kNumOfElements; i++)
	{
		ASSERT_EQ(expected_array[i], actual_array[i]);
	}

	delete[] actual_array, expected_array;
}


TEST(TestSort, TestOneMinusOneArray)
{
	int *expected_array = new int[kNumOfElements];
	int *actual_array = new int[kNumOfElements];

	std::srand(time(0));
	for (int i = 0; i < kNumOfElements; i++)
	{
		expected_array[i] = std::rand() % 2;

		if (expected_array[i] == 0)
		{
			expected_array[i] = -1;
		}
	}

	std::copy(expected_array, expected_array + kNumOfElements, actual_array);
	std::sort(expected_array, expected_array + kNumOfElements);
	DllSelectionSort(actual_array, kNumOfElements);

	for (int i = 0; i < kNumOfElements; i++)
	{
		ASSERT_EQ(expected_array[i], actual_array[i]);
	}

	delete[] actual_array, expected_array;
}

TEST(TestSort, TestEmptyArray)
{
	int* zero_pointer = 0;
	DllSelectionSort(zero_pointer, 0);
	ASSERT_EQ(0, zero_pointer);
}

TEST(TestSort, TestReverseOrderSortedArray)
{
	int *expected_array = new int[kNumOfElements];
	int *actual_array = new int[kNumOfElements];

	for (int i = 0; i < kNumOfElements; i++)
	{
		expected_array[i] = (kNumOfElements - 1) - i;
	}

	std::copy(expected_array, expected_array + kNumOfElements, actual_array);
	std::sort(expected_array, expected_array + kNumOfElements);
	DllSelectionSort(actual_array, kNumOfElements);
	
	for (int i = 0; i < kNumOfElements; i++)
	{
		ASSERT_EQ(expected_array[i], actual_array[i]);
	}

	delete[] actual_array, expected_array;
}

int main(int argc, char *argv[])
{
	const char* kPath = "../../file/file.txt"; 
	int *data = new int[kNumOfElements];
	
	FillingFile(kNumOfElements, kPath);
	ReadingFile(data, kNumOfElements, kPath);
	DllSelectionSort(data, kNumOfElements);
	WritingFile(data, kNumOfElements, kPath);

	delete[] data;

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

void DllSelectionSort(int *data, const int kNumOfElements)
{
	HINSTANCE hinstance_lib;

	void(*DllFunc) (int *data, const int kNumOfElements);

	hinstance_lib = LoadLibrary("../Sort_lib/Debug/Sort_lib.dll");
	if (!hinstance_lib)
	{
		std::cerr << "Error! Sort_lib.dll is not found. \n";
	}

	DllFunc = (void(*) (int *, const int))GetProcAddress(hinstance_lib, "SelectionSort");
	if (!DllFunc)
	{
		std::cerr << "Error! There is no SelectionSort function in Sort_lib.dll. \n";
	}

	DllFunc(data, kNumOfElements);
	FreeLibrary(hinstance_lib);
}
