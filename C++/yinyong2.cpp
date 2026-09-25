#include "iostream"
using namespace std;
//引用作为函数的返回值
//1.不要返回局部变量的引用
//int &test01()
//{
  //int a=10;
  //return a;

//}
//test01() 返回的是栈区局部变量 a 的引用。函数一执行完，a 就被系统自动释放了，ref 就成了悬空引用。
//访问它属于未定义行为，本次运行直接触发了访问违规（内存越界），所以程序崩溃——连第一行都没打印出来。


//2.函数调用可以作为左值使用
int& test02()
{

    static int a=10;//静态变量存放在全局区，程序结束后由系统释放
    return a;
}

int main()
{
 int &ref=test02();
 cout<<"ref="<<ref<<endl;
    test02()=1000;
    cout<<"ref="<<ref<<endl;
    return 0;

  

}