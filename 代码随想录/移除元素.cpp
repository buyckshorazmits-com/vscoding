#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Print(vector<int>&V)
{
    for(vector<int>::iterator it=V.begin(); it!=V.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

//默认输入的数组元素为升序排列
class solutoin
{
    public:
    int search(vector<int>&nums,int target)
    {
        int slowindex=0;//慢指针负责将不是target的元素放入的数组
        for(int fastindex=0;fastindex<nums.size();fastindex++)//快指针检索容器中的元素 与target不同的元素放在新的数组里
        {
            if(nums[fastindex]!=target)
            {
                nums[slowindex]=nums[fastindex];
                slowindex++;
            }
        }
        return slowindex;
    }
};
int main()
{
    
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
   
    int target;
    cin>>target;
    Print(v);

    solutoin s;
    int tar=s.search(v,target);
    v.resize(tar);//去掉容器末尾的无效残渣
    Print(v);
    cout<<"v容器的个数"<<v.size()<<endl;
}