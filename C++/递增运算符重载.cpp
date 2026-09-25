#include "iostream"
using namespace std;
//重载递增运算符
//自定义整型
class MyInteger
{
 friend ostream&operator<<(ostream& cout,MyInteger Myint );
  public:

  MyInteger()
  {
    m_Num=0;
  }

  //重载前置运算符++
  MyInteger& operator++()
  {
    m_Num++;//先进行++
    return *this;//再将自身返回 this本质是指针常量，解引用后为指针所指对象
  }
     //后置++
	//加int是和前置++重载，int为占位参数
	//返回值不加引用，是因为temp为局部变量，用完立马被释放（不能返回局部变量的地址）
	//如果想用引用实现链式递增，可以把用new在堆区创建变量temp，然后手动析构delete
  //重载后置递增运算符
  //void operator++(int )  int 代表占位参数，可以区分前置和后置递增
  MyInteger operator++(int )
  {
    MyInteger temp;
    temp=*this;//记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
     m_Num++;
     return temp;
  }

   private:
    int m_Num;

};
ostream&operator<<(ostream& cout,MyInteger Myint )
{
    cout<<Myint.m_Num;
    return cout;
}
void test1()
{
    MyInteger Myint ;
    cout<<++(++Myint)<<endl;
    cout<<Myint<<endl;
}
void test2()
{
    MyInteger Myint ;
    cout<<Myint++<<endl;
    cout<<Myint<<endl;

}
int main()
{
//test1();
test2();

  return 0;

}