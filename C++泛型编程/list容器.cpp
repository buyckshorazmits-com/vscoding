#include<iostream>
#include<list>
using namespace std;
//采用动态存储分配，不会造成内存浪费和溢出
//链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
//stl中的list是双向链循环链表  元素指向前一个元素的节点  也指向后一个元素的节点
void PrintList(const list<int>&L)
{
    for(list<int> ::const_iterator lit =L.begin();lit !=L.end();lit++)
    {
        cout<<*lit<<" ";
    }
    cout<<endl;
}

void test1()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    PrintList(l1);

    list<int> l2(l1.begin(),l1.end());//将l1begin() 到end()区间内的元素拷贝给l2
    PrintList(l2);

    list <int>l3(l2);//将l2的元素拷贝到l3容器中
    PrintList(l3);

    list <int>l4(10,100);//将10个100拷贝到l4中
    PrintList(l4);
}
int main()
{
    test1();
    system("pause");
    return 0;
}
