#include<iostream>
#include<set>
using namespace std;

void PrintSet(set<int>& S)
{
    for(set<int>::iterator it=S.begin();it !=S.end();it++)
    {
      cout<<*it<<"  ";

    }
    cout<<endl;
}

void test1()
{
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(5);

    set<int>::iterator pos=s1.find(3);//将pos指向为3的元素
    if(pos!=s1.end())//只是判断 pos 这一个结果，并没有把所有元素都判断一遍
    {
        cout<<"找到了该元素"<<endl;
    }
    else
    {
        cout<<"未找到该元素"<<endl;
    }
    int num=s1.count(3);//统计容器中值为3的元素个数 这里的统计结果只能是0或1 set没有重复元素
    cout<<"值为3的元素个数为："<<num<<endl;

}

int main()
{
    test1();
    system("pause");
    return 0;
}