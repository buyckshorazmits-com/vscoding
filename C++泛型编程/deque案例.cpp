#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<ctime>
#include<deque>
using namespace std;
class Person
{
    public:
    Person(string name,int score)
    {
        this->M_name=name;
        this->M_score=score;
    }

    string M_name;
    int M_score;
};
//创建一个类 选手的容器 将选手的信息放入容器 
void CreatPerson(vector<Person>&v)
{
    string nameseed="ABCDE";
    for(int i=0;i<5;i++)
    {
       string name="选手";
       name+=nameseed[i];
       
       int score=0;
       Person p(name,score);
       v.push_back(p);
    }
}

//将评委的分数记录
void setScore(vector<Person>&v)
{
  for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
  {
    //将评委的容器放入到deque容器中
    deque<int> d;
    for(int i=0;i<10;i++)
    {
        int score=rand()% 41+60;
        d.push_back(score);
    }
    /*cout<<"选手"<<it->M_name<<" "<<"分数："<<it->M_score<<" "<<endl;
    for(deque<int>::iterator dit=d.begin();dit !=d.end();dit++)
    {
        cout<<*dit<<"";
    }
    cout<<endl;*/
    sort(d.begin(),d.end());

    //去除一个最高分 一个最低分
    d.pop_back();
    d.pop_front();

    //取平均分

    int sum=0;
    for(deque<int> :: iterator dit=d.begin();dit !=d.end();dit++)
    {
       sum+=*dit;

    }
    int avg=sum /d.size() ;
    it->M_score=avg;
  }
  //排序
   
}
void showScore(vector<Person>&v)
{
    for(vector<Person>::iterator it=v.begin();it !=v.end();it++)
    {
        cout<<"姓名："<<it->M_name<<" "<<"分数："<<it->M_score<<endl;
    }
    
}

int main()
{
    //随机数种子
    srand((unsigned int)time (NULL));
    //创建5名选手
    vector<Person> v;
    CreatPerson(v);

    //给五名选手打分
    setScore(v);

    //显示最后的得分
    showScore(v);

    system("pause");
    return 0;

}