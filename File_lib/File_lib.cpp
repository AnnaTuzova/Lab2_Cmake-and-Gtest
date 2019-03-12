#include "File_lib.h"

void FillingFile(const int kNumOfElements, const char* kPath)
{
	std::ofstream file(kPath, std::ios_base::out | std::ios_base::trunc); 
	if (!file.is_open())
	{
		std::cerr << "File is not open for filling!" << std::endl;
	}

	std::srand(time(0)); 
	for (int i = 0; i < kNumOfElements; i++) 
	{
		file << std::rand() % 1000 << std::endl;
	}

	file.close();
}

void ReadingFile(int *data, const int kNumOfElements, const char* kPath)
{
	std::ifstream file(kPath);
	if (!file.is_open()) 
	{
		std::cerr << "File is not open for reading!" << std::endl;
	}

	file.seekg(0, std::ios_base::end); 
	std::cout << "Size of file: " << file.tellg() << " bytes" << std::endl;
	file.seekg(0, std::ios_base::beg); 

	for (int i = 0; i < kNumOfElements; i++) 
	{
		file >> data[i];
	}

	file.close();
}

void WritingFile(int *sorted_data, const int kNumOfElements, const char* kPath)
{
	std::ofstream file(kPath, std::ios_base::app);
	if (!file.is_open()) 
	{
		std::cerr << "File is not open for writing!" << std::endl;
	}

	file << "Sorted data: " << std::endl;

	for (int i = 0; i < kNumOfElements; i++)
	{
		file << sorted_data[i] << std::endl;
	}

	file.close();
}