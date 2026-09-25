#include "iostream"
#include "string"
#include <windows.h>
using namespace std;
//设计一个学生类，属性有姓名和学号
//可以给姓名和学号赋值，可以显示
class student
{
    //类中的属性和行为  统一称为成员
    //属性  成员属性 成员变量
    //行为  成员函数 成员方法
  public:
  //属性
  string m_name;
  int m_id;

  //行为
void showstudent()
{


    cout<<"姓名："<<m_name<<"  "<<"学号："<<m_id<<endl;
    
}
   //在行为中  完成给姓名赋值操作
   void setname(string name)
   {
       m_name=name;
   }
   //给学号赋值
   void setid(int id)
   {
        m_id=id;
   }
};
int main()
{
    // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，避免中文乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    //创建一个具体学生  实例化对象
    student s1;
    s1.m_name="张三";
    s1.m_id=123456;
    cout<<"这位同学的信息："<<endl;
    s1.showstudent();

    s1.setname("李四");
    s1.setid(123457);
    cout<<"这位同学的信息："<<endl;
    s1.showstudent();



}