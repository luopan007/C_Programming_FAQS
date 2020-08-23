#pragma once

using namespace std;

namespace SortFunction {

	// 1. ѡ������
	template<typename T>
	void selectionSort(T arr[], int length)
	{
		for (int i = 0; i < length; ++i)
		{
			// Ѱ��[i,n)�����������Сֵ
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

	// 2. �������� - ������˿�ȡ��һ��
	template<typename T>
	void insertionSort(T arr[], int length) {
		
		for (int i = 1; i < length; i++)
		{
			// �ӵ�ǰλ�ð�����ǰ�Ƚϣ���arr[i]���뵽���ʵ�λ��
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