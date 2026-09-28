#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int>&L)
{
    for(list<int> ::const_iterator Lit=L.begin();Lit !=L.end();Lit++)
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
    PrintList(L1);

    list<int> L2;
    L2=L1;//operator=  =运算符重载
    //list& operator=(const list &lst)  重载等号操作符
    PrintList(L2);

    list <int> L3;
    L3.assign(L2.begin(),L2.end());
    PrintList(L3);

    list<int> L4;
    L4.assign(10,100);
    PrintList(L4);

}
void test2()
{
    list<int> L5;
    L5.push_back(1);
    L5.push_back(2);
    L5.push_back(3);
    L5.push_back(4);

    list<int> L6;
    L6.push_back(5);
    L6.push_back(6);
    L6.push_back(7);
    L6.push_back(8);
    cout<<"交换前："<<endl;
    cout<<"L5:"<<endl;
    PrintList(L5);
    cout<<"L6:"<<endl;
    PrintList(L6);

    cout<<"交换后："<<endl;
    L5.swap(L6);
    cout<<"L5:"<<endl;
    PrintList(L5);
    cout<<"L6:"<<endl;
    PrintList(L6);
}
int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}