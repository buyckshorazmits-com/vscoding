#include "iostream"
#include "string"
#include "windows.h"
using namespace std;

struct student
{
 string name;
 int age;
 int score;
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  student stu={"张三",18,100};
  student *p=&stu;//结构体指针指向结构体变量 访问->成员运算符
  cout<<"姓名："<<p->name<<"年龄："<<p->age<<"成绩："<<p->score<<endl;  
}