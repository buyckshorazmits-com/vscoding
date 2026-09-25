#include "iostream"
using namespace std;
void maopaopaixu(int arr[],int len)
{
   for(int i=0;i<len-1;i++)
   {
      for(int j=0;j<len-i-1;j++)
      {
         if(arr[j]>arr[j+1])
         { 
           int temp=arr[j];
           arr[j]=arr[j+1];
           arr[j+1]=temp;


         }
      }
   }
}
void printarr(int arr[],int len)
{
  for(int i=0;i<len;i++)
  {

     cout<<arr[i]<<" ";


  }


}
int main()
{
   int arr[]={4,2,6,8,3,1,5,6,9,7,0};
   int len=sizeof(arr)/sizeof(arr[0]);
   maopaopaixu(arr,len);
   printarr(arr,len);


}