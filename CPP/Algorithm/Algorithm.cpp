#include "Algorithm.h"

#include <iostream>

template<typename T>
void Algorithm::insertion_sort(std::vector<T> *arr)
{
	int i, j;
	for (i = 1; i < arr->size(); i++)
	{
		j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			--j;
		}
	}
}

template<typename T>
void Algorithm::swap(T *left, T *right)
{
	T *tmp = *left;
	*left= *right;
	*right = *tmp;
}

int main()
{

	return 0;
}