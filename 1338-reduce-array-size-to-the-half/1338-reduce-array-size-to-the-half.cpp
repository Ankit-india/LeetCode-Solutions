class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans=0;
        int n1=0;
        vector<int> vec;
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0; i< n; i++)  
        {
          mp[arr[i]]++;
        }
    
       for (auto x : mp)
       {
           vec.push_back(x.second);
           
       }
        if(vec.size()==1)return 1;
        sort(vec.begin(), vec.end());
        for(int i=vec.size()-1; i>=0; i--)
        {
            if(ans>=n/2){
              return n1;
        } 
        n1++;
        ans= ans+ vec[i];
        
        }
        return 0;
    }
};