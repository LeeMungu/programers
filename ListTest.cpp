//리스트 구현
#include <iostream>

using namespace std;

template <typename T>
class List final
{
	class Node
	{
	public:
		T mData;
		Node* mNextNode;
		Node* mPrevNode;
		Node()
			:mNextNode(nullptr) {}

		~Node()
		{
			if (mNextNode)
				delete mNextNode;
		}
	};
private:
	Node* mRoot;//첫번째 노드
public:
	List() :mRoot(nullptr) {}
	~List() 
	{ 
		if(mRoot) 
			delete mRoot; 
	}
	void Push_Back(T data)
	{
		Node* newNode = new Node();
		newNode->mData = data;
		newNode->mNextNode = nullptr;
		newNode->mPrevNode = nullptr;
		//1. 처음 넣는 데이터라면?
		if (mRoot == nullptr)
		{
			mRoot = newNode;
		}
		//2.처음 넣는 데이터가 아니라면
		else
		{
			//마지막 노드를 찾는다.
			Node* temp = mRoot;
			while (temp->mNextNode != nullptr)
			{
				temp = temp->mNextNode;
			}
			temp->mNextNode = newNode;
			newNode->mPrevNode = temp;
		}
	}
	void Print()
	{
		if (mRoot == nullptr)
			return;
		Node* temp = mRoot;
		while (temp != nullptr)
		{
			cout << temp->mData << endl;
			temp = temp->mNextNode;
		}
	}
};


int main()
{
	List<int> list;
	for (int i = 0; i < 10; ++i)
	{
		list.Push_Back(i);
	}
	list.Print();
}
