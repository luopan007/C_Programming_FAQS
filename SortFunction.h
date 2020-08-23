#pragma once

using namespace std;

namespace SortFunction {

	// 1. 选择排序
	template<typename T>
	void selectionSort(T arr[], int length)
	{
		for (int i = 0; i < length; ++i)
		{
			// 寻找[i,n)区间里面的最小值
			int minIndex = i;
			for (int j = i + 1; j < length; ++j)
			{
				if (arr[j] < arr[minIndex])
				{
					minIndex = j;
				}
			}

			std::swap(arr[i], arr[minIndex]);
		}
	}

	// 2. 插入排序 - 就像打扑克取牌一样
	template<typename T>
	void insertionSort(T arr[], int length) {
		
		for (int i = 1; i < length; i++)
		{
			// 从当前位置挨个往前比较，将arr[i]插入到合适的位置
			for (int j = i; j > 0; j--)
			{
				if (arr[j] < arr[j - 1]) {
					std::swap(arr[j], arr[j - 1]);
				}
				else {
					break;
				}
			}
		}
	}
}