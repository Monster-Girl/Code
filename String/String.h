#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>

using namespace std;

class String
{
public:
	String(const char* str="")
		:_size(strlen(str))
		, _capacity(_size+1)
	{
		_str = new char[_capacity];
		memcpy(_str, str, _size+1);
	}

	String(const String& s)
		:_str(NULL)
	{
		String tmp(s._str);
		swap(_str,tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
	}

	~String()
	{
		delete[]_str;
	}

	char* GetStr()
	{
		return _str;
	}

	void PushBack(char ch)
	{
		_CheckCapacity(_size+1);
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
		
	}

	void PopBack()
	{
		--_size;
		_str[_size] = '\0';
	}

	void Insert(size_t pos,const char* ch)
	{
		_CheckCapacity(_size + 1);
		int end = _size;
		while (end >= pos)
		{
			_str[end + 1] = _str[end];
			--end;
		}
		++_size;
		_str[end+1] = ch;
	}

	void Erase(size_t pos)
	{
		assert(pos < _size);
		for (size_t i = pos + 1; i <= _size; i++)
		{
			_str[i-1] = _str[i];
		}
		--_size;
		_str[_size] = '\0';
	}

	//查找子串
	/*size_t Find_Str(const char* sub)
	{
		size_t SrcSize = _size;
		size_t SubSize = strlen(sub);
		size_t SrcIndex = 0;


		while (SrcIndex <= _size - SubSize)
		{
			size_t SubIndex = 0;
			size_t begin = SrcIndex;
			while (begin < SrcSize
				&&SubIndex < SubSize
				&&_str[begin] == sub[SubIndex])
			{
				begin++;
				SubIndex++;
			}
			if (SubIndex == SubSize)
			{
				return SrcIndex;
			}
			SrcIndex++;
		}
		return -1;
	}*/
	
	
	//size_t Find(const char* sub)
	
	bool operator==(const String& s)
	{
		if (_size == s._size)
		{
			for (size_t i = 0; i<_size; i++)
			{
				if (_str[i] != s._str[i])
					return false;
			}
		}
		return true;
	}

	bool operator>(const String& s)
	{
		char* str1 = _str;
		char* str2 = s._str;
		while (*str1 && *str2)
		{
			if (*str1 > *str2)
				return true;
			else if (*str1 < *str2)
				return false;
			else
			{
				++str1;
				++str2;
			}
		}

		if (*str2)
			return false;
		else
			return true;
	}

	bool operator<(const String& s)
	{
		return!(*this>s || *this == s);
	}

	bool operator<=(const String& s)
	{
		return!(*this > s);
	}
	
	bool operator>=(const String& s)
	{
		return!(*this < s);
	}
	
	String& operator+(char ch)
	{
		String tmp(*this);
		tmp.Insert(tmp._size, ch);
		return tmp;
	}

	//operator+=
	//operator[]

	 
private:
	void _CheckCapacity(size_t NeedSize)
	{
		if (NeedSize >= _capacity)
		{
			size_t NewCapacity = _capacity * 2;
			_capacity = NewCapacity;
			assert(_str);
		}
	}

private:
	char* _str;
	size_t _size;    //字符长度
	size_t _capacity;   //容量
};