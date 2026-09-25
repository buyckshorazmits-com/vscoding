#include"iostream"
using namespace std;
//类模板
template<class NameType,class AgeType>
class Person 
{
   public:
   Person(NameType name ,AgeType age)
   {
       this->m_Name=name;
       this->m_Age=age;
   }
   void showPerson()
   {
    cout<<"name:"<<this->m_Name<<" "<<"age="<<this->m_Age<<endl;
   }

   NameType m_Name ;
   AgeType  m_Age ;
};
//类模板在模板参数列表中可以有默认参数
template<class NameType ,class  AgeType=int>
class NewPerson
{
    public:
    NewPerson(NameType name,AgeType age )
    {
        this->m_Name=name;
        this->m_Age=age;
    }

   void showNewPerson()
   {
    cout<<"name="<<this->m_Name<<" "<<" age="<<this->m_Age<<endl;
   }
    NameType m_Name;
    AgeType m_Age;
};

void test2()
{
    NewPerson p1("王五",19);//C++17之前类模板没有自动类型推导的使用方式  也就是说这么写是错误的
    p1.showNewPerson();

    NewPerson<string>p2 ("赵六",18);//显示指定类型
    p2.showNewPerson();
}


void test1()
{
    Person P1("张三",18);//Person<const char*, int> P1("张三", 18);C++17
    // NameType 推导为 const char*（字符串字面量的类型）
    // AgeType  推导为 int
    P1.showPerson();
    Person <string ,int>P2("李四",19);//这里直接指明NameType 推导为 string   AgeType  推导为 int
    P2.showPerson();
}
int main()
{
   test1();
   test2();
   return 0;
}