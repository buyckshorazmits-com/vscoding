#include<iostream>
using namespace std;
// 通过全局函数打印Person的信息
//提前让编译器知道Person类存在
template<class T1, class T2>
class Person; 
//类外实现
template<class T1, class T2>
void   showPerson2(Person <T1,T2>p)
{
    cout<<"类外实现:"<<p.m_name<<p.m_age<<endl;
}

template <class T1,class T2>
class Person 
{
    friend void PrintPerson(Person<T1,T2>p)
    {
        //全局函数类内实现
        cout<<p.m_name<<p.m_age<<endl;
    }
    //全局函数类外实现
	//加空模板参数列表
	//如果全局函数 是类外实现 需要让编译器提前知道这个函数的存在
	friend void showPerson2<>(Person<T1, T2>p);
    public:
    Person (T1 name,T2 age)
    {
        this->m_name=name;
        this->m_age=age;

    }
    private:
    T1 m_name;
    T2 m_age;

};
void test1()
{
    Person <string,int >p("zbc",12);
    PrintPerson(p);
}
void test2()
{
    Person<string, int>p2("年轻人", 18);

}
int main()
{
   
    test2();
    system("pause");
    return 0;
}