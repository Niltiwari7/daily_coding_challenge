#include<iostream>
#include<queue>
using namespace std;

int kth_largest_ele(int *arr,int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<n;i++)pq.push(arr[i]);
   for(int i=0;i<n-k;i++)
   {
    pq.pop();
   }
    return pq.top();
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<kth_largest_ele(arr,n,k);
}