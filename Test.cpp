#include<iostream>
using namespace std;
//17-3-1
//�õݹ�ʵ���������
//int AddAll(int arr[],int begin,int length)   //������arr����begin�������ĺ�
//{
//	if (begin == length) return 0;
//	int sum = AddAll(arr, begin+1,length);
//	return sum + arr[begin];
//}
//
//
//int main()
//{
//	int arr[] = {1,2,3,4,5,6 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int sum = AddAll(arr, 0, length);
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}

//#include<string>
//�õݹ��ж��ַ��������Ƿ����
//bool IsEqual(string s1, string s2)
//{
//	int str1 = s1.length();
//	int str2 = s2.length();
//	if (str1 != str2) return false;
//	//if ((str1 == 0) && (str2 == 0)) return true;
//	if (str1 == 0) return true;
//	/*if ((s1.substr(0, 1)) != (s2.substr(0, 1)))
//		return false;*/
//
//	std::string::iterator it1=s1.begin();
//	std::string::iterator it2 = s2.begin();
//	if (*it1 != *it2) return false;
//
//	return IsEqual(s1.substr(1,str1), s2.substr(1,str2));
//}
//
//
//int main()
//{
//	string s1 = "hello world";
//	string s2 = "hello world";
//	bool ret = IsEqual(s1, s2);
//	cout << ret << endl;
//	//cout << s1.compare(s2) << endl;
//	system("pause");
//	return 0;
//}

//17-3-2
//��n�����У���һȡm�������Żأ������ж�����ȡ��
//int f(int n, int m)
//{
//	//a,b,c 
//	//ab,bc,ac
//	if (n < m) return 0;
//	if (n == m) return 1;
//	if (m == 0) return 1;
//
//	//n������һ������ģ�ȡ�����֣�����������������
//	//Ҫô�ڱ�ȡ�ķ�Χ�Ҫô�Ͳ�������,�������
//	return (f(n - 1, m - 1) + f(n - 1, m));
//}
//
//int main()
//{
//	int k = f(10, 3);
//	cout << k << endl;
//	system("pause");
//	return 0;
//}

//��n��Ԫ�ص�ȫ����
//#include<string>
//void f(string arr,int k)   //��ǰ�Ľ���λ��
//{
//	int len = arr.length();
//	if (k == (len-1))
//	{
//		for (int i = 0; i < len; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = k; i < len; i++)
//	{
//		swap(arr[k], arr[i]);//��̽
//		f(arr,k+1);
//		swap(arr[k], arr[i]);//����
//	}
//}
//
//int main()
//{
//	string arr= "abc";
//	f(arr,0);
//	system("pause");
//	return 0;
//}

//������������󹫹������еĳ���
//��������ָ��һ�����п�������ȡ��һЩȡ��һЩ��ȡ��
//#include<string>
//#include <algorithm>  
//int f(string s1, string s2)
//{
//	int str1 = s1.length();
//	int str2 = s2.length();
//	if (str1 == 0 || str2 == 0) return 0;
//	if (s1.substr(0,1) == s2.substr(0,1))
//		return   f((s1.substr(1, str1)), (s2.substr(1, str2))) + 1;
//	else
//	{
//		return max(f(s1.substr(1, str1), s2), f(s1, s2.substr(1, str2)));
//		/*if (f(s1.substr(1, str1), s2) > f(s1, s2.substr(1, str2)))
//			return f(s1.substr(1, str1), s2);
//		else
//			return f(s1, s2.substr(1, str2));*/
//	}
//}
//
//int main()
//{
//	string s1 = "abc";
//	string s2 = "xbacd";
//	int k = f(s1, s2);
//	cout << k << endl;
//	system("pause");
//	return 0;
//}
//�ܽ᣺�����ĳ��ȹ���ʱ���ݹ齫��ʧЧ���������Ž⣬�����Բ��ߡ� 

//2017-3-4
//ʵ�ִ��ķ���
//#include<string>
//string f(string arr)
//{
//	if (arr=="" || arr.length() <= 1) return arr;
//	return f(arr.substr(1))+ arr.substr(0,1);
//}
//
//int main()
//{
//	string ret = f("abc");
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}

//�������
//#include<iomanip>
//int f(int m, int n)  //m��n��Ԫ��
//{
//	if (m == 0) return 1;
//	if (n == 0 || n == m) return 1;
//	return f(m - 1, n - 1) + f(m - 1, n);
//}
//
//int main()
//{
//	int level = 5;
//	
//	for (int i = 0; i <= level; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			cout << setw(3) << f(i, j) << "  " << setw(3);
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//3��A,2��B,�ж���������
//int f(int m, int n)  //m��A��n��B
//{
//	if (m == 0 || n == 0) return 1;
//	return f(m - 1, n) + f(m, n - 1);
//}
//
//int main()
//{
//	cout << f(3, 2) << endl;
//	system("pause");
//	return 0;
//}

//�����Ļ�������
//#include<malloc.h>
//void f(int n,int arr[],int k)
//{
//	if (n <= 0)
//	{
//		for (int i = 0; i<k; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = n ; i > 0; i--)
//	{
//		if (k > 0 && i > arr[k - 1]) continue;
//		arr[k] = i;
//		f(n - i, arr, k + 1);
//	}
//}
//
//int main()
//{
//	int *arr = new int[100];
//	f(6, arr, 0);
//	system("pause");
//	return 0;
//}

//err_sum���д�ĺ�
//int arr:��ϸ
//k:��ǰ�Ĵ���λ��
//cur_sum:ǰ��Ԫ�ص��ۼӺ�
void f(int err_sum, int arr[], int k,int cur_sum,int length,bool b[])
{
	if (cur_sum > err_sum) return;  //���ۼӺ� > �д�ĺͣ�����
	if (k > length) return;    //��kԽ�磬����

	if (err_sum == cur_sum)     //���ۼӺ� = �д�ĺ� ����ʼ��Ǵ�ӡ
	{
		for (int i = 0; i < length; i++)
		{
			if (b[i]==false)
				cout << i << " ";
		}
		cout << endl;
		return;
	}

	//����������������ǰkҪ��Ҫ�ӽ�ȥ��
	b[k] = false;    //1.������ӣ���ֱ�ӽ�����һ���ݹ�
	f(err_sum, arr, k + 1, cur_sum,length,b);

	b[k] = true;        //2.������ˣ�cur_sum�����ı䣬Ҳ������һ���ݹ�
	cur_sum += arr[k];
	f(err_sum, arr, k + 1, cur_sum,length,b);

	b[k] = false;    //����
}

int main()
{
	int arr[] = { 3, 2, 4, 3, 1 };
	int sum = 6;
	int length = sizeof(arr) / sizeof(arr[0]);
	bool* b = new bool[length];   //������b ����Ƿ�ѡȡ
	f(6, arr, 0,0,length,b);
	system("pause");
	return 0;
}