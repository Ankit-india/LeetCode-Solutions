// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
      
        Rearrange( arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} // } Driver Code Ends




void Rearrange(int arr[], int n)
{
    // Your code goes here
    queue<int> neg,pos;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            neg.push(arr[i]);
        }
        else{
            pos.push(arr[i]);
        }
    }
    
    for(int i = 0; i < n; i++){
        while(!neg.empty()){
            arr[i] = neg.front();
            i++;
            neg.pop();
        }
        while(!pos.empty()){
            arr[i] = pos.front();
            i++;
            pos.pop();
        }
    }
    
}