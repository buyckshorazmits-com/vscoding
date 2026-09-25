#include<iostream>
#include<stack>
#include<cstdlib>   // system()
using namespace std;
//stack容器是一个先进后出的容器 只有栈顶一个出口
void test1()
{
    stack <int> s;
    //入栈  向栈顶存数据
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //查看栈的大小
    cout<<"栈的大小："<<s.size()<<endl;

    //只要栈不为空 就执行出栈操作
    while(!s.empty())
    {
        cout<<s.top()<<endl;//获取栈顶的值  不做任何操作 只看
        s.pop();//删除栈顶的值
    }
    cout<<"栈的大小："<<s.size()<<endl;

}
  int main()
  {
    test1();
    system("pause");
    return 0;
  }