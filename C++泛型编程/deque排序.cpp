#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void Printdeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it !=d.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}

void test1()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);

    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    Printdeque(d1);
    //默认升序排列 
    //对于随机迭代器的容器  都可以使用sort算法去排序

    cout<<"排序后："<<endl;
    sort(d1.begin(),d1.end());
    Printdeque(d1);

}
int main()
{
    test1();
    system("pause");
    return 0;
}