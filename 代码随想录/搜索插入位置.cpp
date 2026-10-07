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
        int left=0;
        int right=nums.size()-1;//// 定义target在左闭右闭的区间里，[left, right]
        while (left<=right)
        {// 当left==right，区间[left, right]依然有效，所以用 <=
            int middle=left+((right-left)/2);// 防止溢出 等同于(left + right)/2
            if(nums[middle]<target)// target 在右区间，所以[middle + 1, right]
            {
                left=middle+1;
            }
            else if(nums[middle]>target)// target 在左区间，所以[left, middle - 1]// target 在右区间，所以[middle + 1, right]
            {
                right=middle-1;
            }
            else// nums[middle] == target
            {
                return middle;
            }
        }
        // 如果能找到 target，直接返回其下标
        // 如果找不到，当循环结束时 left > right，且 left = right + 1
        // 此时 left 正好是 target 应该插入的位置
        return right+1;
    }
};
int main()
{
    
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);
    v.push_back(11);
    v.push_back(13);
    v.push_back(15);
    int target;
    cin>>target;
    Print(v);

    solutoin s;
    int tar=s.search(v,target);
    cout<<"target的下标"<<tar<<endl;
}
