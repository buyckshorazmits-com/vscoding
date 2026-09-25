#include"iostream"
using namespace std;
void myPrint(int a,int b)
{
    cout<<"调用普通函数"<<endl;

}
template <class T>
void myPrint(T a,T b)
{
    cout<<"调用模板函数"<<endl;
}
template <class T>
void myPrint(T a,T b,T c )
{
    cout<<"调用重载模板函数"<<endl;
}


int main()
{
int a=10;
int b=20;
myPrint(a,b);//如果函数模板和普通函数都可以调用。优先调用普通函数。普通函数只有声明会报错

myPrint<>(a,b);//通过空模板的参数列表强制调用函数模板

myPrint(a,b,100);//调用重载模板

char c1='a';
char c2='b';
myPrint(c1,c2);//用char 类型时  此时与函数模板更匹配  
}