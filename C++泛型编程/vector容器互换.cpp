#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void printVector(vector <int>&v)
{
    for(vector<int>::iterator it=v.begin();it !=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test1()
{
 vector <int>v1;
 cout<<"交换前"<<endl;
 for(int i=0;i<10;i++)
 {
    v1.push_back(i);
}
printVector(v1);
vector <int>v2;

for(int i=10;i>0;i--)
{
  v2.push_back(i);
}
printVector(v2);

cout<<"交换后："<<endl;
v1.swap(v2);

printVector(v1);

printVector(v2);

}
//实际 用途
//巧用swap可以收缩内存空间

void test2()
{
   vector<int> v;
   for(int i=0;i<10000;i++)
   {
    v.push_back(i);
   }
   cout<<"容量:"<<v.capacity()<<endl;
   //v.capacity()返回的是 vector 底层已经分配好的缓冲区能容纳的元素个数
   cout<<"大小:"<<v.size()<<endl;
   cout<<endl;
   v.resize(3);
   //重新指定容量大小
   cout<<"容量："<<v.capacity()<<endl;
   cout<<"大小："<<v.size()<<endl;

   //用swap去收缩内存
   vector<int> (v).swap(v);
   cout<<endl;
   cout<<"容量："<<v.capacity()<<endl;
   cout<<"大小："<<v.size()<<endl;
}

int main()
{
  test1();
  test2();
  system ("pause");
  return 0;

}