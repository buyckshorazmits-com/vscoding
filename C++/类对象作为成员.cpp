#include"iostream"
#include "string"
using namespace std;
class Phone
{
 public:
    Phone (string name)
  {
    m_PhoneName=name;
    cout<<"Phone构造"<<endl;

  }
  ~Phone()
  {
   cout<<"Phone析构"<<endl;

  }

 string m_PhoneName;

};
class Person
{
  public:
  //初始化列表构造函数
  Person(string name,string pName):m_Name(name),m_Phone(pName){
    cout<<"Person构造"<<endl;

  

  }
  ~Person ()
  {
   cout<<"Person析构"<<endl;

  }
void playGame()
{
 cout<<m_Name<<"使用"<<m_Phone.m_PhoneName<<"手机"<<endl;

}

string m_Name;
Phone m_Phone;

};
void test1()
{ 
   Person p("张三","苹果max");
    p.playGame();
  //当类中成员是其他类对象时，我们称该成员为 对象成员
	//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
	//析构顺序与构造相反

}
int main()
{
    test1();
   return 0;


}