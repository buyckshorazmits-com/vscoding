#include "iostream"
#include <windows.h>
using namespace std;
//将所有成员属性设置为私有，可以控制读写权限
class Person
{
//姓名设置可读可写
public:
 void setname(string name )
{
 m_name=name;
}
string getname()
{
 return m_name;
}
//年龄只读
int getage()
{
    return m_age;
}
//idol设置为只写
void setidol(string idol)
{
    m_idol=idol;

}
private:
string m_name;//可读可写  姓名

int m_age=18;//只读  年龄

string m_idol;//只写 偶像

};

int main()
{
    // 设置控制台代码页为 UTF-8，配合源文件的 UTF-8 编码，避免中文乱码
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  Person p;
  //姓名设置
  p.setname("张三");
  cout<<"姓名："<<p.getname()<<endl;
  //年龄读取
  cout<<"年龄："<<p.getage()<<endl;
//idol 设置
  p.setidol("IU");
  //cout<<"偶像："<<p.m_idol;<<endl; 只写属性  不可读取

  return 0;
}
