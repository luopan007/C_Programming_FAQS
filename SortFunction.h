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

	// 2. 插入排序 - 就像打扑克取牌一样 - 挨个交换
	template<typename T>
	void insertionSort_Swap(T arr[], int length) {
		
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

	// 2. 插入排序 - 就像打扑克取牌一样 - 比较赋值
	template<typename T>
	void insertionSort_Move(T arr[], int length) {

		for (int i = 1; i < length; i++)
		{
			// 记录待排序的元素
			T element = arr[i];
			
			// 待排序元素前面的所有元素都是从小到大的循序，下标 j 保存最后一个比待排序元素大的元素下标
			int j;

			// 循环继续的条件是：待排序元素存在比其大的元素
			for (j = i; j > 0 && arr[j-1] > element; j--)
			{
				arr[j] = arr[j - 1]; // 把比待排序元素大的元素往后移动
			}

			// 经过前面的依次后移，j位置是空的，需要将待排序元素填入此位置
			arr[j] = element;
		}
	}
}