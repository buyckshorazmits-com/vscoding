#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int>L)
{
    for(list<int> ::const_iterator Lit=L.begin();Lit !=L.end();Lit++)
    {
        cout<<*Lit<<" ";

    }
    cout<<endl;
    
}

void test()
{
    list <int> L1;
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    PrintList(L1);

    if(L1.empty())//返回值是布尔类型  判断容器是否为空
    {
        cout<<"空"<<endl;

    }
    else
    {
        cout<<"不空"<<endl;
        cout<<"元素个数="<<L1.size()<<endl;

    }
    //重新指定大小
    L1.resize(10,1000);//将容器的长度改成10  后面的位置用1000补充
    PrintList(L1);
}
int main()
{
    test();
    system("pause");
    return 0;
}