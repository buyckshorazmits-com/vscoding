#include "iostream"
#include <windows.h>
using namespace std;
//对象的初始化和清理
//1.构造函数  进行初始化操作
class Person 
{
    public:
    //1.构造函数
    //没有返回值  不用写void
    //函数名  与类名相同
    //构造函数可以有参数，可以发生重载
    //创建对象的时候，构造函数会自动调用 并且只调用一次

    Person()
    {
    
     cout<<"Person构造函数的调用"<<endl;
    }

    //2.析构函数  对象被销毁前会自动调用
    //没有返回值  不用写void
    //函数名与类名相同，在名称前加~
    //构造函数不可以有参数，不可以发生重载
    //创建对象的时候，构造函数会自动调用 并且只调用一次
    ~Person()
    {

        cout<<"Person析构函数的调用"<<endl;
    }
};
//析构和构造都是必须有的实现，如果自己不提供，编译器会提供一个空实现的构造和析构
void test1()
{
   Person p;//在栈上的数据  test1执行完后，释放这个对象


}
int main()
{
    // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，避免中文乱码
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  test1();//此时会直接在test函数中调用



}