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

	// 2. �������� - ������˿�ȡ��һ�� - ��������
	template<typename T>
	void insertionSort_Swap(T arr[], int length) {
		
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

	// 2. �������� - ������˿�ȡ��һ�� - �Ƚϸ�ֵ
	template<typename T>
	void insertionSort_Move(T arr[], int length) {

		for (int i = 1; i < length; i++)
		{
			// ��¼�������Ԫ��
			T element = arr[i];
			
			// ������Ԫ��ǰ�������Ԫ�ض��Ǵ�С�����ѭ���±� j �������һ���ȴ�����Ԫ�ش��Ԫ���±�
			int j;

			// ѭ�������������ǣ�������Ԫ�ش��ڱ�����Ԫ��
			for (j = i; j > 0 && arr[j-1] > element; j--)
			{
				arr[j] = arr[j - 1]; // �ѱȴ�����Ԫ�ش��Ԫ�������ƶ�
			}

			// ����ǰ������κ��ƣ�jλ���ǿյģ���Ҫ��������Ԫ�������λ��
			arr[j] = element;
		}
	}
}