#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void  myPrint(int val)
{
  cout<<val<<endl;

} 
void test1()
{
    vector <int> v;
    //向容器中插入数据
    v.push_back(10);//尾插法
    v.push_back(20);//尾插法
    v.push_back(30);//尾插法
    v.push_back(40);//尾插法

    //通过迭代器访问容器中的数据
    //vector<int>::iterator itBegin =v.begin();////起始迭代器，指向容器中第一个元素
    //vector<int>::iterator itEnd =v.end();//结束迭代器，指向容器中的最后一个元素的下一个位置

    //第一种遍历方式
    //while(itBegin !=itEnd)
    //{
    //   cout<<*itBegin<<endl;
    //   itBegin++;
    //}
    //第二种遍历方式
    for(vector <int>::iterator it=v.begin();it !=v.end();it++)
    {
        cout<<*it<<endl;

    }
    //第三种遍历方式利用STL提供的算法实现
    //for_each(v.begin(),v.end(),myPrint);//for_each(起始迭代器, 结束迭代器, 处理函数);

}
int main(void)
{
  test1();
  system("pause");
  return 0;
}