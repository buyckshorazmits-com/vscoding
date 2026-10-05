#include<iostream>
#include<string>
using namespace std;
//成对出现的数据，利用对组可以返回两个数据。


void test1()
{
    //第一种
    pair <string ,int> p("tom",18);//直接调用构造函数
    cout<<p.first<<"  "<<p.second<<endl;

    //第二种
    pair <string ,int> p1=make_pair("jerry",12);
    //make_pair("jerry", 12) 推导出的其实是 pair<const char*, int>（字符串字面量是 const char*），
    //赋值给 pair<string,int> 时会通过转换构造把 const char* 转成 string。
    cout<<p1.first<<" "<<p1.second<<endl;
}
int main()
{
    test1();
    system("pause");
    return 0;
}