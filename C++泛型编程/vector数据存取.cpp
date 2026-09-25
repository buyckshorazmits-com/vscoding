#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//除了用迭代器获取vector中元素，[]和at也可以
//front返回容器第一个元素
//back返回容器最后一个元素
//vecor数据存取
void test()
{
  vector <int>v1;
  for(int i=0;i<10;i++)
  {
    v1.push_back(i);

  }
  //利用[]访问数组里的元素
  for(int i=0;i<10;i++)
  {
    cout<<"v1="<<v1[i]<<endl;
  }
  cout<<endl;

  //利用at去访问元素
  for(int i=0;i<v1.size();i++)
  {
    cout<<v1.at(i)<<" ";
  }
  cout<<endl;
  //获取第一个元素
  cout<<"第一个元素是"<<v1.front()<<endl;
  //获取最后一个元素
  cout<<"最后一个元素是"<<v1.back()<<endl;

}
int main()
{
  test();
  system("pause");
  return 0;
}
