#pragma once

using namespace std;

namespace SortFunction {

	// 1. 选择排序 O(n²)
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

	// 2. 插入排序 O(n²) - 就像打扑克取牌一样 - 挨个交换
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

	// 2. 插入排序 - O(n²) 就像打扑克取牌一样 - 比较赋值
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

	// 2.1 插入排序 -- 针对某个区间进行插入排序
	template<typename T>
	void __insertionSort(T arr[], int left, int right) {
		for (int i = left +1; i <= right; i++)
		{
			T element = arr[i];
			int j;
			for (j = i; j > left && arr[j - 1] > element; j--) {
				arr[j] = arr[j - 1];
			}
			arr[j] = element;
		}
	}
	
	// 辅助函数：合并两个有序的子数组
	template<typename T>
	void __merge(T arr[], int left, int mid, int right) {
		T *tmp = new T[right - left + 1];          // 缓存当前数组
		// 对于边长数组 VS 不支持 T tmp[right - left + 1] 的写法
		for (int i = left; i <= right; i++)
		{
			tmp[i - left] = arr[i];
		}
		
		int i = left;                       // i代表左边有序数组的起始位置
		int j = mid + 1;                    // j代表右边有序数组的起始位置
		for (int k = left; k <= right; k++) // k 代表合并后数组的下标
		{
			if (i > mid) {                  // 左边没有元素，直接把右边的元素依次赋值给合并后的数组
				arr[k] = tmp[j - left];
				j++;
			}
			else if (j > right)             // 右边没有元素，直接把左边的元素依次赋值给合并后的数组
			{ 
				arr[k] = tmp[i - left];
				i++;
			}
			else if (tmp[i - left] < tmp[j - left]) { // 依次比较 左边小于右边，左边赋值给合并后的数组
				arr[k] = tmp[i - left];
				i++;
			}
			else
			{
				arr[k] = tmp[j - left];      // 依次比较 右边小于左边，右边赋值给合并后的数组
				j++;
			}
		}

	}

	// 辅助函数：递归使用并归排序，对arr[left...right]的范围进行排序
	template<typename T>
	void __mergeSort(T arr[], int left, int right) {
		//if (left >= right) {
		//	return;
		//}

		// 优化2：针对数组长度减少到一定长度时，有序的概率很高，可以采用插入排序
		if (right - left <= 15) {
			__insertionSort(arr, left, right);
			return;
		}

		int mid = (left + right) / 2;
		__mergeSort(arr, left, mid);
		__mergeSort(arr, mid + 1, right);

		// 经过上述递归后，左边和右边必然是有序的子数组
		// 接下来需要使用合并函数合并
		// 优化1：只有左边的最大的元素大于右边最小的元素才需要merge操作
		if (arr[mid] > arr[mid + 1]) {
			__merge(arr, left, mid, right);
		}
	}

	// 3. 归并排序O(n*logn)
	template<typename T>
	void mergeSort(T arr[], int n) {
		__mergeSort(arr, 0, n - 1);
	}

	// 辅助函数 - 对数组进行分组
	// 对数组 arr[left...right]进行分组，使得arr[left...part] < arr[part] 且 arr[part+1...right] > arr[part]
	template<typename T>
	int __partition(T arr[], int left, int right) {
		T v = arr[left]; // 随机选择 arr[part]值为数组的第一个元素

		int j = left;
		for (int i = left + 1; i <= right; i++) {
			if (arr[i] < v) {
			std::swap(arr[j + 1], arr[i]);
			j++;
			}
		}

		std::swap(arr[left], arr[j]);
		return j;
	}

	// 辅助函数 - 快速排序
	template<typename T>
	void __quickSort(T arr[], int left, int right) {
		if (left >= right) {
			return;
		}
		// 对于所有的高级排序算法，都可使用插入排序优化
		// 见归并算法的优化2

		int part = __partition(arr, left, right);
		__quickSort(arr, left, part);
		__quickSort(arr, part + 1, right);
	}

	// 4. 快速排序 -- 第一版
	template<typename T>
	void quickSort(T arr[], int length) {
		__quickSort(arr, 0, length - 1);
	}
}