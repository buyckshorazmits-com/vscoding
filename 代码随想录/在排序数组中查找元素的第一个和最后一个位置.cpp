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
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int first=-1;
       int last=-1;
       int left=0;
       int right=nums.size()-1;
       while(left<=right)
       {
        int middle=left+((right-left)/2);
        if(nums[middle]>target)  //num[middle]>target时  num[middle]在target右边  此时要向左搜索 
        {
            right=middle-1;//这样写是为了 不包含middle
        }
        else if(nums[middle]<target)//num[middle]<target时  num[middle]在target左边  此时要向右搜索
        {
            left=middle+1;
        }
        else
        {
            first=middle;
            right=middle-1;
        }
       }
        left=0;
        right=nums.size()-1;
       while(left<=right)
       {
         int mid=left+(right-left)/2;
        if(nums[mid]>target)
        {
            right=mid-1;
        }
        else if(nums[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            last=mid;
            left=mid+1;
        }
       }
        return {first,last};
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

    Solution s;
    s.searchRange(v,target);
    
}
