#include "iostream"
#include "windows.h"
using namespace std;
int main()
{
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);
  int a=10;
  int *p;
  p=&a;
  cout<<"a的地址为："<<&a<<endl;
  cout<<"p指向的值为："<<*p<<endl;
  cout<<"指针p为："<<p<<endl;
  cout<<"指针p的地址为："<<&p<<endl;


}