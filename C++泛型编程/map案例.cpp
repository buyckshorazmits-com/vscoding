#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Woker
{
    public:
    string m_name;
    int m_Salary;
};
void CreatWorker(vector<Woker>&v)
{
    string NameSeed = "ABCDEFGHIJ";
    for(int i=0;i<10;i++)
    {
        Woker woker;
        woker.m_name="worker";
        woker.m_name+=NameSeed[i];
        
        woker.m_Salary=rand()%10000+10000;
        //将员工放在容器中
        v.push_back(woker);
    }
}
//分组
void SetGroup(vector<Woker>& v,multimap<int,Woker>& m)
{
    for(vector<Woker>::iterator it=v.begin();it!=v.end();it++)
    {
        //产生随机编号
        int deptId =rand()%3;//0  1  2
        //key值为部门编号 ，value值为员工
        m.insert(make_pair(deptId,*it));

    }
}
//分组显示

void ShowWorkerByGroup(multimap<int,Woker> &m)
{
    cout<<"策划部门："<<endl;
    multimap<int,Woker>::iterator pos=m.find(CEHUA);
    int count=static_cast<int>(m.count(CEHUA));//返回CEHUA的个数

    int index=0;
    for(;pos !=m.end()&& index<count;pos++,index++)
    {
    
        cout<<"姓名："<<pos->second.m_name<<" "<<"工资："<<pos->second.m_Salary<<endl;
    }
    cout<<"美术部门："<<endl;
    pos=m.find(MEISHU);
    count=static_cast<int>(m.count(MEISHU));
    index=0;
    for(;pos !=m.end()&&index<count;pos++,index++)
    {
        cout<<"姓名："<<pos->second.m_name<<" "<<"工资："<<pos->second.m_Salary<<endl;
    }


    cout<<"研发部门："<<endl;
    pos=m.find(YANFA);
    count=static_cast<int>(m.count(YANFA));
    index=0;
    for(;pos !=m.end()&&index<count;pos++,index++)
    {
         cout<<"姓名："<<pos->second.m_name<<" "<<"工资："<<pos->second.m_Salary<<endl;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    //创建员工
    vector<Woker>Worker;
    CreatWorker(Worker);

    //分组
    multimap<int,Woker>mWorker;
    SetGroup(Worker,mWorker);

    //分组显示员工
    ShowWorkerByGroup(mWorker);

    system("pause");
    return 0;

}
