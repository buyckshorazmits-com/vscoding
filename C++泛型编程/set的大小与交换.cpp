#include<iostream>
#include<set>
using namespace std;
//size()  返回容器中元素的个数
//empty()  判断容器是否为空
//swap()  交换两个容器的元素
void PrintSet(const set<int>& s)
{
    for(set<int>::iterator it=s.begin();it !=s.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;
}
void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    PrintSet(s1);

    if(s1.empty())
    {
        cout<<"s1为空"<<endl;
    }
    else
    {
        cout<<"s1不为空"<<endl;
        cout<<"s1的大小为："<<s1.size()<<endl;
    }

    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(400);
    PrintSet(s2);

    cout<<"交换前："<<endl;
    PrintSet(s1);
    PrintSet(s2);

    cout<<"交换后："<<endl;
    s2.swap(s1);
    PrintSet(s1);
    PrintSet(s2);

}
int main()
{
    test01();
    system("pause");
    return 0;
}