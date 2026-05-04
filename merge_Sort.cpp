#include<iostream>
#include<utility>
#include<vector>
using namespace std;
void merged(vector<int>&arr,int l,int mid,int r)
{
    vector<int> temp;
    int i=l;
    int j=mid+1;

    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j]) //descending er jnno >hbe
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+l]=temp[idx];
    }
}
void mergeSort(vector<int>&arr, int l, int r)
{
    if(l<r)
    {
        int mid =(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merged(arr,l,mid,r);
    }
}

int main()
{
    vector<int>arr = {23,14,3,7,9,10};
    mergeSort(arr,0,arr.size()-1);
    for(int val:arr)
    {
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}
