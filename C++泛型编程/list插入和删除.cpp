#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int>&L)
{
    for(list<int>::const_iterator Lit=L.begin();Lit !=L.end();Lit++)
    {
        cout<<*Lit<<" ";
    }
    cout<<endl;
}
void test1()
{
    list<int> L1;
    //尾插
    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);
    L1.push_back(4);
    //头插
    L1.push_front(10);
    L1.push_front(20);

    PrintList(L1);

    //删除元素
    L1.pop_back();
    L1.pop_front();
    PrintList(L1);

    //插入元素
    list<int>::iterator it =L1.begin();
    it++;
    L1.insert(it,1000);//在it+1位置之前插入1000 打印出来就是 10 1000 1 2 3 
    PrintList(L1);

    //删除
    //用的时候指定it
    it=L1.begin();
    L1.erase(++it);//删除it+1位置的元素
    PrintList(L1);
    //移除
    L1.push_back(1000);
    L1.push_back(1000);
    L1.push_back(1000);
    PrintList(L1);
    L1.remove(1000);//删除容器中所有与括号内相同的元素  删除所有1000

    PrintList(L1);
    //清空
    L1.clear();
    PrintList(L1);
}

int main()
{
    test1();
    system("pause");
    return 0;
}