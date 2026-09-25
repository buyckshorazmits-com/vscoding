#include<iostream>
#include<deque>
using namespace std;

void printdeque(const deque<int>&v)
{
    for(deque<int>:: const_iterator it =v.begin();it!=v.end();it++)
{
    cout<<*it<<" ";
}
cout<<endl;
}
void test1()
{
    deque <int> d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);

    deque<int>d2(d1.begin(),d1.end());//将d1容器中begin 到end 区间内的元素拷贝到d2中
    printdeque(d2);

    deque<int> d3(10,100);//将10个100拷贝到d3 容器中
    printdeque(d3);

    deque<int>d4(d3);
    printdeque(d4);
}
int main()
{
    test1();
    system("pause");
    return 0;
}