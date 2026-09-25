#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//vector 预留空间
void test1()
{
 vector<int> v1;
 int num=0;
 int *p=NULL;

 for(int i=0;i<10000;i++)
 {
    v1.push_back(i);
    if(p!=&v1[0])
    {
      p=&v1[0]; 
      num++;  //首地址变化的次数 = 分配次数 = 扩容次数 + 1
      //g++ 是 2 倍增长  内存容量是由2的倍数增长
    }
 }
 cout<<"num="<<num<<endl;
}
int main()
{
    test1();
    system("pause");
    return 0;

}