// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int isPlaindrome(int n){
        string str = to_string(n);
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i] != str[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i = 0; i < n; i++){
    	    if(!isPlaindrome(a[i])){
    	        return 0;
    	    }
    	}
    	return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends