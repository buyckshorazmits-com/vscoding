#include<iostream>
#include<list>
using namespace std;
//list容器中不可以通过[]或者at方式访问数据
//返回第一个元素——front    返回最后一个元素——back
void PrintList(const list<int>&L)
{
    for(list<int>::const_iterator Lit=L.begin();Lit!=L.end();Lit++)
    {
        cout<<*Lit<<" ";
    }
    cout<<endl;
}
void test1()
{
    list<int> L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);

    //list中不可以用[]去访问容器中的元素
    //at()也不行
   //因为List本质是链表，不是用连续的线性空间存储数据，迭代器也是不支持随机访问的
   cout<<"第一个元素："<<L1.front()<<endl;
   cout<<"最后一个元素："<<L1.back()<<endl;

   list<int>::iterator it=L1.begin();
   it++;
   it--;
   
   //支持++ --双向操作
   //it=it+1 ;这样操作不行 不支持随机访问
}
int main()
{
    test1();
    system("pause");
    return 0;
}