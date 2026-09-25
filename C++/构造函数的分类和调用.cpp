#include"iostream"
#include <windows.h>
using namespace std;

class Person
{
 public:
 //无参（默认）构造函数
 Person()
 {
    cout<<"无参构造函数"<<endl;

 }
 Person(int a)
 {
    age=a;
  cout<<"有参构造函数"<<endl;  
 }

 //拷贝函数    类名（const 类名 &对象名）
 Person(const Person &p)
 {
  age=p.age;
  cout<<"拷贝构造函数"<<endl;

 }
 //析构函数
 ~Person()
 {
  cout<<"析构函数的调用"<<endl;

 }
 public:

 int age;
};
//构造函数的调用
void test1()
{
    Person p;//调用无参的构造函数
    //注意：调用无参构造函数不能加括号，如果加了编译器会认为这是一个函数声明 Person p();
}
//调用有参构造函数
void test2()
{
 //括号法
 Person p1(10);//有参构造
 Person p5(p1);//拷贝构造

 //显示法
 Person p2=Person(10);//有参构造
 Person p3=Person(p2);//拷贝构造
 // Person(10);//单独写就是没有创建明确对象  当这行结束后 马上析构

//隐式转换
Person p4=10;//Person p4=Person(10);
Person p6=p4;//Person p5=Person(p4);

//注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明 Person(p2);等效于Person p2 调用无参构造函数，与上诉有参构造发生重定义，报错
}


int main()
{
    // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，避免中文乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    //test1();
     test2();
    
     return 0;


}