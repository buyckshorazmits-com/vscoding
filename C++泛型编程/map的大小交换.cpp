#include<iostream>
#include<map>
using namespace std;

void PrintMap(map<int,int>&m)
{
    for(map<int,int>::iterator it =m.begin();it != m.end();it++)
    {
        cout<<"key="<<(*it).first<<"  "<<"value="<<(*it).second<<" ";
    }
    cout<<endl;
}

void tes1()
{
    map<int,int>m1;
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));

    PrintMap(m1);

    if(m1.empty())
    {
        cout<<"空"<<endl;

    }
    else 
    {
        cout<<"不空"<<endl;
        cout<<"大小："<<m1.size()<<endl;
    }

    map <int,int>m2; 
    m2.insert(pair<int,int>(10,1));
    m2.insert(pair<int,int>(20,2));
    m2.insert(pair<int,int>(30,3));
    m2.insert(pair<int,int>(40,4));

    cout<<"交换前："<<endl;
    PrintMap(m1);
    PrintMap(m2);

    cout<<"交换后："<<endl;
    m2.swap(m1);

    PrintMap(m1);
    PrintMap(m2);
}
int main()
{
    tes1();
    system("pause");
    return 0;
}