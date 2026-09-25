#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//string 字符存取 
void test1()
{
    string str="hello";
    //通过[]访问单个字符
    for(int i=0;i<str.size();i++)
    {
       cout<<str[i]<<" ";

    }
    cout<<endl;
    //通过at的方式访问单个字符
    for(int i=0;i<str.size();i++)
    {
     cout<<str.at(i)<<" ";
    }
    cout<<endl;
    //修改单个字符
    str[0]='z';
    cout<<str[0]<<endl;

    str.at(0)='x';
    cout<<str[0]<<endl;

}
int main()
{
   test1();
   system("pause");
   return 0;
}