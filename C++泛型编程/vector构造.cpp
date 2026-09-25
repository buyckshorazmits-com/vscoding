#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void  printVector(vector <int>&v)
{
    for(vector<int>::iterator it=v.begin();it !=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}
//vector容器构造
void test1()
{
//vector是一个动态数组
  vector<int> v1;//默认构造  无参构造

  for(int i=0;i<10;i++)
  {
    v1.push_back(i);
  }
  printVector(v1);

  //通过区间的方式去构造
  vector<int> v2(v1.begin(),v1.end());
  printVector(v2);

  //n个elem
  vector<int> v3(10,100);
  printVector(v3);

  //拷贝构造
  vector<int> v4(v3);
  printVector(v4);


}
int main()
{
    test1();
    system("pause");
    return 0;
}
