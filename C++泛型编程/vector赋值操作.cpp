#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void printVector(vector<int> &v)
{
    for(vector<int> ::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}
void test1()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //赋值opreator=操作
    vector <int> v2;
    v2=v1;
    printVector(v2);

    //assign操作
    vector<int> v3;
    v3.assign(v1.begin(),v1.end());
    //先清空容器里原有的所有元素，
    //再把新内容放进去（是“替换/覆盖”，不是“追加”）。
    printVector(v3);

    //n个elem
    vector<int> v4;
    v4.assign(10,100);
    printVector(v4);
}
int main()
{
    test1();
    system("pause");
    return 0;
}