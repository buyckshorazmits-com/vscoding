#include<iostream>
#include<map>
using namespace std;

// 仿函数:作为map的第三个模板参数,指定key的排序规则
// operator()必须加const:map要求在const对象上也能调用比较器
// (如const成员函数find、遍历内部,比较器对象是const MyCompare),
// 不加const时GCC/新版MSVC会报"passing 'const MyCompare' as 'this' argument discards qualifiers"
// 另外,比较操作本身也不应修改自身状态,const也表达了这一语义
class MyCompare
{
    public:
    bool operator()(int v1,int v2)const
    {
        return v1>v2;// 返回true表示v1排在v2前面 -> key降序(默认less是升序)
    }
};

void PrintMap(map<int,int,MyCompare>& m)
{
    for(map<int,int,MyCompare>::iterator it =m.begin();it !=m.end();it++)
    {
        cout<<"key="<<(*it).first<<" "<<(*it).second<<endl;
    }
    cout<<endl;
}

void test1()
{
    map<int,int,MyCompare>m1;
    m1.insert(make_pair(1,10));
    m1.insert(make_pair(2,20));
    m1.insert(make_pair(3,30));
    m1.insert(make_pair(4,40));
    m1.insert(make_pair(5,50));

    PrintMap(m1);

}
int main()
{
    test1();
    system("pause");
    return 0;
}