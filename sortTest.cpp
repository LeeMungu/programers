#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


/*
선택 정렬 O(n^2) 
탐색해서 가장 작거나 큰애를(기준에 맞는) 가장 앞에 보내면서 
탐색구간을 줄이는 방식으로 무조건 모두 탐색한다.
*/
vector<int> SelectSort(vector<int>& input)
{
	for (int j = 0; j < input.size(); ++j)
	{
		int minimum = j;
		for (int i = j; i < input.size(); ++i)
		{
			if (input[minimum] > input[i])
			{
				minimum = i;
			}
		}
		swap(input[minimum], input[j]);

		//출력
		for (int i : input)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return input;
}

//힙 만들어 주는 친구
void heap(vector<int>& input, int num)//크기순으로 정렬 해주는애
{
	for (int i = 1; i < num; ++i)
	{
		int child = i;
		while (child > 0)
		{
			int root = (child - 1) / 2;
			if (input[root] < input[child])
			{
				swap(input[root], input[child]);
			}
			child = root;
		}
	}
	for (int x : input)
		cout << x << " ";
	cout << endl;
}

//힙정렬 보통 O(nlogn)의 시간 복잡도를 가짐
void heapSort(vector<int>& input)
{
	heap(input, input.size());
	//힙을 만든다(==부모자식간 순차 정렬이 된다.)

	//뒤엣친구를 힙최상단과 바꿔치기 하면서 정렬 새로 시킨다.
	//->정렬 후에는 최말단은 탐색에서 제외
	for (int i = input.size() - 1; i > 0; --i)
	{
		swap(input[i], input[0]);
		heap(input, i);
	}
}

void QuickSort(vector<int>& input, int left, int right)
{
	//원소가 한개 이하인 경우
	if (left >= right)
		return;
	int pivot = left;//왼쪽시작 피벗
	int st = left + 1;//최대값 찾는 친구
	int en = right;//최소값 찾는 친구
	
	while (st <= en)
	{
		while (st <= right &&
			input[st] <= input[pivot]) 
		{
			st++;
		}
		while (en > left &&
			input[en] >= input[pivot])
		{
			en--;
		}

		//서로 엇갈린 경우
		if (st > en)
		{
			swap(input[en], input[pivot]);
		}
		else
		{
			swap(input[st], input[en]);
		}
	}
	for (int i=left; i>right+1; ++i)
		cout << input[i] << " ";
	cout << endl;

	//재귀로 분할 구현
	QuickSort(input, left, en - 1);
	QuickSort(input, en + 1, right);
}

int main()
{
	vector<int> mVector = { 23,123,324234,12312,2123,24,456,56,123,564 };
	//처음 배열 값
	for (int x : mVector)
		cout << x << " ";
	cout << endl;
	
	//선택정렬
	//SelectSort(mVector);
	
	//힙정렬
	//heapSort(mVector);

	//퀵정렬
	QuickSort(mVector, 0, mVector.size()-1);
}