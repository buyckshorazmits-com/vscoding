#include<iostream>
#include<set>
using namespace std;
//内置类型
class MyCompare//← 这个类就是"仿函数" 
{
    public:
    //set 内部保存了一个 MyCompare 对象（作为成员），内部比较函数 _M_key_compare 本身是 const 成员函数，所以它访问到的比较器成员也是 const 对象；
    //const 对象只能调用带 const 的成员函数 → operator() 必须加 const。
    bool operator()(int value1,int value2)const
    {
       return value1>value2;
    }
};
void tes1()
{
    set<int,MyCompare>s1;//"装 int 元素、用 MyCompare 的方式决定大小顺序的 set"。set<int, MyCompare> 是编译器按模板"生成"出来的一个具体类，s1 是它的一个对象。
    //set容器在还没插入数据之前 进行排序
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    for(set<int,MyCompare>::iterator it=s1.begin();it !=s1.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;
}
int main(void)
{
    tes1();
    system("pause");
    return 0;
}

