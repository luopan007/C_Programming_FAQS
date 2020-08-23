#pragma once

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
using namespace std;


namespace SortTestHelper {
	
	// 该函数生成 n 个元素的随机数组，每个数组的随机范围是 [rangeLeft,rangeRight]
	int* generateRandomArray(int n, int rangeLeft, int rangeRight) {
		assert(rangeLeft <= rangeRight);
		
		int *result = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			result[i] = rand() % (rangeRight - rangeLeft + 1) + rangeLeft;
		}
		return result;
	}

	// 生成一个几乎有序的数组
	int* generateNearlyOrderedArray(int length, int swapTimes) {
		int *result = new int[length];
		for (int i = 0; i < length; i++)
		{
			result[i] = i;
		}
		
		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++)
		{
			int posx = rand() % length;
			int posy = rand() % length;
			std::swap(result[posx], result[posy]);
		}

		return result;
	}

	// 检验数组是否为从小到大的有序数组
	template<typename T>
	bool isSort(T arr[], int n) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}
		return true;
	}

	// 传入函数名，和排序的函数指针，待排序的数组和数组长度
    // 打印该排序函数耗时
	template<typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSort(arr, n));
		
		cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	}

	template<typename T>
	void printArray(T array[], int n) {
		for (int i = 0; i < n; i++)
		{
			std::cout << array[i] << " ";
		}
		cout << endl;
	}

	int* copyIntArray(int a[], int n) {
		int* result = new int[n];
		copy(a, a + n, result);
		return result;
	}
}