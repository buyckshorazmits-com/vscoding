#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
void test1()
{
//string的构造函数
 string  s1;//默认构造
 const char *str="hello world!";
 string s2(str);
 cout<<"s2:"<<s2<<endl;

 string s3(str);
 cout<<"s3:"<<s3<<endl;
}
int main()
{
    test1();
    system("pause");
    return 0;
}