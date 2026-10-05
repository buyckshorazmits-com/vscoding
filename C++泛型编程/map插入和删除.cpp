#include<iostream>
#include<map>
using namespace std;

void PrintMap(map<int,int>&m)
{
    for(map<int,int>::iterator it =m.begin();it != m.end();it++)
    {
        cout<<"key="<<(*it).first<<"  "<<"value="<<(*it).second<<" ";
    }
    cout<<endl;
}
void test1()
{
    
   map<int,int> m1;
   //第一种
   m1.insert(pair<int,int>(1,10));
   //第二种
   m1.insert(make_pair(2,20));
   //第三种
   m1.insert(map<int,int>::value_type(3,30));
   //第四种
   m1[4]=40;
   //不建议这种方式 它的用途是利用key访问value，不存在是自动创建，所以应该确定存在时在访问
   cout<<m1[4]<<endl;

   PrintMap(m1);
   m1.erase(m1.begin());
   PrintMap(m1);

   m1.erase(3);//利用key值删除
   PrintMap(m1);

   m1.erase(m1.begin(),m1.end());
   PrintMap(m1);

   m1.clear();
   PrintMap(m1);
}
int main()
{
    test1();
    system("pause");
    return 0;
    
}
