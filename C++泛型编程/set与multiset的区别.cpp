#include<iostream>
#include<set>
using namespace std;
//set不可以插入重复数据，而multiset可以
//set插入数据的同时会返回插入结果，表示插入是否成功
//multiset不会检测数据，因此可以插入重复数据
void PrintMultiset(multiset<int>& s)
{
    for(multiset<int>::iterator it=s.begin();it !=s.end();it++)
    {
        cout<<*it <<"  ";
    }
    cout<<endl;
}

void  test1()
{
    set<int> s1;
    pair<set<int>::iterator,bool>ret =s1.insert(10);
    //set 的单元素 insert 会返回一个 pair（对组）：两个信息打包在一起——① 元素在哪（迭代器）② 插入成功没有（bool）。
    //pair<A, B> p;
    //p.first;    A 类型
    //p.second;   B 类型
    if(ret.second)
    {
        cout<<"插入成功"<<endl;
    
    }
    else
    {
        cout<<"插入失败"<<endl;
    }
    ret=s1.insert(10);

    if(ret.second)
    {
        cout<<"插入成功"<<endl;
 
    }
    else
    {
        cout<<"插入失败"<<endl;
    }

    multiset<int> s2;
    s2.insert(10);
    s2.insert(10);
    PrintMultiset(s2);

}
int main()
{
    test1();
    system("pause");
    return 0;
}
