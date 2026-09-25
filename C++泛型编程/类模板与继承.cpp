#include<iostream>
using namespace std;

//类模板与继承
template<class T>
class  Base  
{
  public:
  T m;
};

class Son :public Base<int>//必须要知道父类中T的数据类型才能继承给子类
{

};

void test1()
{
    Son s1;
}
//如果想灵活指定父类中T类型，子类也需要变类模板
template<class T1,class T2>
class Son2:public Base<T2>
{
public:
  Son2()
  {
    cout<<typeid(T1).name()<<endl;
    cout<<typeid(T2).name()<<endl;
  }
  T1 Obj;
};
void test2()
{
    Son2<int ,char> S2;
}
int main()
{
    test2();
    system("pause");
    return 0;
}