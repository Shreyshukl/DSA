#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cout<<"enter limit"<<endl;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i]
  }
  int i=0,j=n-1;
  while(i<j)
  {
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
  }
  cout<<"Reversed Array"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" "<<endl;
  }
}
