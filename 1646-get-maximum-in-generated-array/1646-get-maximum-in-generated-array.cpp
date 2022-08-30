class Solution {
    int get(int n)
    {
         if(n==0)return 0;
        else if(n==1)return 1;
       else if(n%2==0)
        {
           int t= get(n/2);
            return t;
        }
        else
        {
             int t= get(n/2);
             int t2= get((n/2)+1);
            return t+t2;
        }
    }
    public:
    int getMaximumGenerated(int n) {
        
     int ans=INT_MIN;
        for(int i=0;i<=n;i++)
        {
            int r=get(i);
            ans = max(r,ans);
        }
        return ans;
    }
};