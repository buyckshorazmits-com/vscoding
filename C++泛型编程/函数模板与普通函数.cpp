#include "iostream"
 using namespace std;

 //普通函数与函数模板的区别
//普通函数调用可以发生隐式类型转换
//函数模板用自动类型推导不可以发生隐式类型转换
// 函数模板用显式指定类型 可以发生隐式类型转换

//普通函数隐式类型转换
 int MyAdd01(int a,int b)
 {
    return a+b;
 }
//函数模板
template <class T>
int MyAdd02(T a,T b)
{
    return a+b;
}
int main()
{
    int a=10;
    int b=20;
    char c='a';

    int ret=MyAdd01(a,b);
    cout<<"ret="<<ret<<endl;
    int ret1=MyAdd01(a,c); //ret1=107
     cout<<"ret1="<<ret1<<endl;

    // cout<<MyAdd02(a,c)<<endl;//自动类型推导不行
    cout<<MyAdd02<int>(a,c)<<endl;//显式指定类型行
    return 0;
}