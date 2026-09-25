#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test1()
{
    //string 求字符串
    string str1="abcdef";
    string subStr=str1.substr(1,3);
    cout<<"subStr="<<subStr<<endl;

}
//使用操作
void test2()
{
    string email="zhangsan@qq.com";
    //从邮箱地址中获取用户名信息
    int pos=email.find("@");
    string usrName=email.substr(0,pos);//返回从零号位置到@位置的字符串

    cout<<"usrName="<<usrName<<endl;

}
int main(void)
{
    test1();
    test2();
    system("pause");
    return 0;
}