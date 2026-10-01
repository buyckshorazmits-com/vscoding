//set 容器的所有元素都会在插入时被自动排序。
//set/multiset属于关联式容器，底层结构是用二叉树实现。
//set不允许容器中有重复的元素。
//multiset允许容器中有重复的元素
#include<iostream>
#include<set>
using namespace std;
//创建set容器和赋值
void PrintSet(const set<int>& s)
{
    for(set<int>::iterator it =s.begin(); it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test1()
{
    set<int> s1;
    //插入数据  插入数据时 只能使用insert 数据插入后会自动排序
    //set不允许容器中有重复的元素
    s1.insert(20);
    s1.insert(10);
    s1.insert(490);
    s1.insert(30);
    PrintSet(s1);

    set<int> s2(s1);//拷贝构造函数  将s1容器中的数据拷贝到s2中

    PrintSet(s2);

    set<int> s3;
    s3 =s2;//重载运算符=  将s2容器中的数据赋值给s3   
    //拷贝构造与运算符=的区别：拷贝构造函数是创建一个新的容器，并将已有容器中的数据拷贝到新容器中，
    //而运算符=是将已有容器中的数据赋值给另一个已有的容器。
    PrintSet(s3);

}
int main()
{
    test1();
    system("pause");
    return 0;
}