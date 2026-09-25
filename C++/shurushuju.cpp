#include "iostream"
#include "string"
#include <windows.h>
using namespace std;
int main()
{
  SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
  int a=0;//整型
  cout<<"请输入一个整数："<<endl;
  cin>>a;
  int b=a%2;
  cout<<"b="<<b<<endl;
   //字符串
   string  str="hello world";
   cout<<"请输入字符串"<<endl;
   cin>>str;
   cout<<"字符串str="<<str<<endl;
  
}
