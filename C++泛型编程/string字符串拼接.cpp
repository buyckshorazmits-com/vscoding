#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void test1()
{
     /*string& operator+=(const char* str)重载+=操作符
     string& operator+=(const char c)重载+=操作符
     string& operator+=(const string& str)重载+=操作符
     string& append(const char* s)把字符串s连接到当前字符串结尾
     string& append(const char* s，int n)把字符串s的前n个字符连接到当前字符串的结尾
     string& append(const string &s)同operator+=(const string& str)
     string& append(const string &s,int pos,int n)把字符串s中从pos开始的n个字符连接到字符串结尾*/
    string str1="你";
    str1+="是伞兵";
    cout<<"str1="<<str1<<endl;

    str1+="?";
    cout<<"str1="<<str1<<endl;

    string str3 = "You";
	str3.append(" SB");
	cout << "str3=" << str3 << endl;

	str3.append("hahaha hahaha", 4);
	cout << "str3=" << str3 << endl;
    str3.append(str1);
	cout << "str3=" << str3 << endl;

	str3.append(str1, 0, 1);
	cout << "str3=" << str3 << endl;
}
int main()
{
    test1();
    system("pause");
    return 0;
}
