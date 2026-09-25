#include"iostream"
using namespace std;

void mySwap(int &a,int &b)
{
//引用传递的方式交换两个变量的值，在函数中形参会修饰实参的值
int temp=a;
a=b;
b=temp;

    
}
int main()
{
  //引用的基本语法 
  //数据类型  &别名=原名
  //引用必须初始化 
  //在初始化后，就不能更改，就不能指向其他变量
  //引用本质上相当于利用一个新的变量指向原变量，在初始化过后，指向的方向是固定的，不能更改
  int a=10;
  int &b=a;
  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;

  b=100;

  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
  
  int c=30;
  b=c;//这个不是改变引用的指向，而是将c的值赋给了a，因为b是a的引用
  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
  cout<<"c="<<c<<endl; 
 int d=50;
 int e=60;
 mySwap(d,e);
cout<<"d="<<d<<endl;
cout<<"e="<<e<<endl;


}