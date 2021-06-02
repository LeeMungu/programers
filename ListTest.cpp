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
public:
	//반복자iterator 구현 
	//&참조자, *포인터 차이
	//1. 내부 데이터 요소를 가저올 수 있어야 한다.
	//2. 내부 데이터 요소를 수정할 수 있어야 한다.
	//3. 다음 데이터로 넘어갈 수 있어야 한다.
	//4. 이전 데이터로 넘어갈 수 있어야 한다.
	class Iterator final
	{
	private:
		friend class List;//friend : 클래스에 접근할수 있게 해주는 애
		Node* mCurrentNode;
	public:
		Iterator() : mCurrentNode(nullptr) {}
		//연산자 재정의========================
		Iterator& operator++()
		{
			mCurrentNode = mCurrentNode->mNextNode;
			return *this;
		}
		//=====================================
		Iterator& operator--()
		{
			mCurrentNode = mCurrentNode->mPrevNode;
			return *this;
		}
		//=====================================
		T& operator*()
		{
			return mCurrentNode->mData;
		}
		//=====================================
		bool operator==(const Iterator& iter)
		{
			return mCurrentNode == iter.mCurrentNode;
		}
		//=====================================
		bool operator!=(const Iterator& iter)
		{
			return mCurrentNode != iter.mCurrentNode;
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
	Iterator Begin()
	{
		Iterator iter;
		iter.mCurrentNode = mRoot;
		return iter;
	}

	Iterator End()
	{
		Iterator iter;
		iter.mCurrentNode = nullptr;
		return iter;
	}
};

int main()
{
	List<int> list;
	for (int i = 0; i < 10; ++i)
	{
		list.Push_Back(i);
	}
	//함수를 이용한 출력
	//list.Print();

	//이터레이터를 이용한 출력
	List<int>::Iterator iter = list.Begin();
	for (; iter != list.End(); ++iter)
	{
		cout << *iter << endl;
	}
}
