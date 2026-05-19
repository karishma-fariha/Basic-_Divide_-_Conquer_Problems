#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int Partition(vector<int>&arr,int l,int r)
{
    int idx=l-1,pivot=arr[r];
    for(int j=l; j<r; j++)
    {
        if(arr[j]<pivot)//des er jnno>
        {
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[r],arr[idx]);
    return idx;
}
void quickSort(vector<int>&arr,int l,int r)
{
    if(l<r)
    {
        int pvtIdx=Partition(arr,l,r);
        quickSort(arr,l,pvtIdx-1);
        quickSort(arr,pvtIdx+1,r);
    }

}
int main()
{
    vector<int>arr= {12,31,35,8,32,17};
    quickSort(arr,0,arr.size()-1);
    for(int val: arr)
    {
        cout <<val<<" ";
    }
    cout<< endl;
    return 0;
}
