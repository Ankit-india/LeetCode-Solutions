// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    stack<int> pos, neg;
	    for(int i = n-1; i >= 0; i--){
	        if(arr[i] >= 0){
	            pos.push(arr[i]);
	        }
	        else {
	            neg.push(arr[i]);
	        }
	    }
	    vector<int> ans;
	    for(int i = 0; i < n; i++){
	        if(i % 2 == 0){
	            if(!pos.empty()){
	                int temp2 = pos.top();
	                ans.push_back(temp2);
	                pos.pop();
	            }
	        }
	        else{
	            if(!neg.empty()){
	                int temp3 = neg.top();
	                ans.push_back(temp3);
	                neg.pop();
	            }
	        }
	    }
	    while(!pos.empty()){
	        int temp = pos.top();
	        ans.push_back(temp);
	        pos.pop();
	    }
	    while(!neg.empty()){
	        int temp = neg.top();
	        ans.push_back(temp);
	        neg.pop();
	    }
	    int i = 0;
	    for(auto x: ans){
	        arr[i] = x;
	        i++;
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends