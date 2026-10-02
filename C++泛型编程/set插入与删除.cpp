#include<iostream>
#include<set>
using namespace std;
//查找——find(返回的是迭代器)
//统计——count(对于set,结果为0或者1)
void PrintSet(const set<int>& S)
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
    s1.insert(3);
    s1.insert(2);
    s1.insert(5);

    PrintSet(s1);

    s1.erase(s1.begin());//删除第一个元素
    PrintSet(s1);

    s1.erase(3);//删除值为3的元素
    //set 底层是二叉树，不支持随机访问——没有 []、没有 at()，“位置”只能靠迭代器表示
    //这里填数字  只能匹配容器中元素的值，不能表示位置
    PrintSet(s1);

    s1.erase(s1.begin(),s1.end());//删除所有元素
    PrintSet(s1);

    s1.clear();//清空容器

    PrintSet(s1);
}
//返回值：按值删除返回删除的个数（set 只会是 0 或 1）；按迭代器删除返回被删元素的下一个位置
int main()
{
    test1();
    system("pause");
    return 0;
}