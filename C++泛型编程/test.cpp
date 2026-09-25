#include "Myarry.hpp"
#include<iostream>
#include<string.h>
using namespace std;

void PrintArry(Myarry <int> &arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<arr[i]<<endl;
    }
}
void test1()
{
    Myarry <int> arr1(5);
    for(int i=0;i<5;i++)
    {
        //利用尾插法像数组中插入数据
        arr1.PushBack(i);
    }
    cout<<"arr1的打印输出"<<endl;
    PrintArry(arr1);
    cout<<"arr1的容量为 ："<<arr1.getCapacity()<<endl;
    cout<<"arr1的大小为："<<arr1.getSize()<<endl;

    cout<<"打印arr2的输出"<<endl;
    Myarry <int> arr2(arr1);

    PrintArry(arr2);

    //尾删法
    arr2.PopBack();
    cout<<"尾删后:"<<endl;
    cout<<"arr2的容量："<<arr2.getCapacity()<<endl;
    cout<<"arr2的大小："<<arr2.getSize()<<endl;


}
//测试自定义数据类型
class Person
{
    public: 
    Person(){};
    Person (string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }

    string  m_name;
    int m_age;

};
void PrintpersonArray(Myarry <Person> &arr)
{
    for(int i=0;i<arr.getSize();i++)
    {
        cout<<"姓名："<<arr[i].m_name<<"年龄："<<arr[i].m_age<<endl;
    }
}
void test02()
{
	Myarry<Person>arr(10);
	Person p1("伞兵1", 21);
	Person p2("伞兵2", 22);
	Person p3("伞兵3", 23);
	Person p4("伞兵4", 24);
	Person p5("伞兵5", 25);

	//将数据插入到数组中
	arr.PushBack(p1);
	arr.PushBack(p2);
	arr.PushBack(p3);
	arr.PushBack(p4);
	arr.PushBack(p5);

	//打印数组
	PrintpersonArray(arr);
//输出容量
	cout << "arr容量为" << arr.getCapacity() << endl;
	//输出大小
	cout << "arr大小为" << arr.getSize() << endl;
}

int main()
{
    test1();
    test02();
    system ("pause");
    return 0;

}


