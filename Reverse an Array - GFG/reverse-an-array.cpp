#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(auto& x: arr) cin >> x;
	    int i = 0, j = n -1;
	    while(i <= j){
	        swap(arr[i], arr[j]);
	        i++;
	        j--;
	    }
	    for(auto x: arr){
	        cout << x << " ";
	    }
	    cout << '\n';
	}
	return 0;
}