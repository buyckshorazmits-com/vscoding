#include "iostream"
using namespace std;
//空指针访问成员函数
class Person
{
 public :
void showclassName()
{
  cout<<"我是Person类"<<endl;

}
void showperson()
{
    //如果用到this指针，需要加以判断保证代码的健壮性 如果为空指针直接返回，程序不会崩
    if(this==NULL)
    {
        return ;
    }
    cout<<this->mAge<<endl;//编译器找不到具体的对象，因此会崩掉
}

int mAge;
};
int main()
{
    Person *p=NULL;
  p->showclassName();//空指针是可以访问成员函数
  p->showperson();

}