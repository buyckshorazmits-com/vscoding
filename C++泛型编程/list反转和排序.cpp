#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void PrintList(const list<int> &L)
{
    for(list<int>:: const_iterator Lit=L.begin();Lit !=L.end();Lit++ )
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

    cout<<"反转前: "<<endl;
    PrintList(L1);

    cout<<"反转后："<<endl;
    L1.reverse();
    PrintList(L1);
}
bool myCompare(int V1,int V2)
{
    return V1>V2;
}

void test2()
{
    list<int> L2;

    L2.push_back(20);
    L2.push_back(30);
    L2.push_back(10);
    L2.push_back(40);
    L2.push_back(5);

    cout<<"排序前："<<endl;

    PrintList(L2);
    //所有不支持随机访问迭代器的容器不可以用标准算法
	//不支持随机访问迭代器的容器，内部会提供对应的一些算法

    //排序后

    L2.sort();//sort()默认是升序排列
    PrintList(L2);

    L2.sort(myCompare);//降序排列
    ////sort() 内部反复把元素两两传入 myCompare 比较,
//根据返回值(true=第一个参数排前面)挪动元素位置,最终呈降序
    PrintList(L2);
}
int main()
{
    test1();
    test2();
    system("pause");
    return 0;
}