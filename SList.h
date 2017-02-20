#pragma once
#include<iostream>
using namespace std;

template <class T>
struct ListNode
{
	T _data;
	ListNode<T>*  _next;
	ListNode<T>*  _prev;

	ListNode(const T& x = T())
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	List(const List<T>& l)
	{
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;

		Node* cur = (l._head)->_next;
		while (cur != l._head)
		{
			this->PushBack(cur->_data);
			cur = cur->_next;
		}
	}

	List<T>& operator=(const List<T>& l)
	{
		if (this != &l)
		{
			Node* cur = l._head->_next;
			while (cur != l._head)
			{
				this->PushBack(cur->_data);
				cur = cur->_next;
			}
		}

		return *this;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = NULL;
	}
	

	void Print()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	void PushBack(const T& x)
	{
		Node* tail = _head->_prev;
		Node* tmp = new Node(x);
		tail->_next = tmp;
		tmp->_prev = tail;

		tmp->_next = _head;
		_head->_prev = tmp;
	}

	void PopBack()
	{
		Node* tail = _head->_prev;
		Node* tmp = tail->_prev;
		tmp->_next = _head;
		_head->_prev = tmp;
	}

	void PushFront(const T& x)
	{
		Node* tmp = new Node(x);
		Node* cur = _head->_next;

		tmp->_prev = _head;
		tmp->_next = cur;

		_head->_next = tmp;
		cur->_prev = tmp;
	}

	void PopFront()
	{
		Node* cur = _head->_next;
		Node* next = cur->_next;

		next->_prev = _head;
		_head->_next = next;

	}

	Node* Find(const T& x)
	{
		Node* tmp = new Node(x);
		Node* cur = _head->_next;
		while (cur != _head)
		{
			if (cur->_data == tmp->_data)
				return cur;
			cur = cur->_next;
		}
		return 0;
	}

	// 在pos的前面插入一个节点
	void Insert(Node* pos, const T& x)
	{
		Node* tmp = new Node(x);
		Node* cur = pos->_prev;

		cur->_next = tmp;
		tmp->_prev = cur;

		tmp->_next = pos;
		pos->_prev = tmp;
	}

	void Erase(Node* pos)
	{
		Node* next = pos->_next;
		Node* pre = pos->_prev;

		next->_prev = pre;
		pre->_next = next;
	}

	void Clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}

		_head->_prev = _head;
		_head->_next = _head;
	}

protected:
	Node* _head;
};


void Test()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.Print();

	//l.PopBack();
	//l.PopBack();
	//l.Print();

	//l.PushFront(5);
	//l.PushFront(6);
	//l.PushFront(7);
	//l.Print();

	//l.Insert(l.Find(2), 5);
	//l.Print();

	//l.PopFront();
	//l.PopFront();
	//l.Print();

	//l.Erase(l.Find(2));
	//l.Print();

	//l.Clear();
	//l.Print();

	List<int> l1(l);
	l1.Print();

	List<int> l2 = l1;
	l2.Print();
	
}