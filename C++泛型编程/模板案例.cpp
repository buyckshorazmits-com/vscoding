#include"iostream"
using namespace std;
//实现通用 对数组进行排序的函数
//规则 从大到小、
//选择排序
//测试 char数组  int数组
//交换的函数模板
template<class T>
void Myswap(T &a,T &b)
{
    T temp =a;
    a=b;
    b=temp;

}
//降序排列
template <class T>
void My_Sort(T arr[],int len)
{
   
   for(int i=0;i<len;i++)
   {
        int maxNum=i;
    for(int j=i+1;j<len;j++)
    {
        if(arr[maxNum]<arr[j])
        {
            maxNum=j;
        }
    }
    if(maxNum!=i)
    {
        T temp=arr[maxNum];
        arr[maxNum]=arr[i];
        arr[i]=temp;
    }
   }
   //
}
//打印数组
template <class T>
void print(T arr[],int len)
{
   for(int i=0;i<len;i++)
   {
    cout<<arr[i]<<endl;
   }
}

int main()
{
     int Intarray[]={1,4,3,2,8,9,2,10};
    int len=sizeof(Intarray)/sizeof(Intarray[0]);
    My_Sort(Intarray,len);
    print(Intarray,len);

    char Chararray[]="adcbus";
    int len1=sizeof(Chararray)/sizeof(Chararray[0]);
    My_Sort(Chararray,len1);
    print(Chararray,len1);

    return 0;
    
}