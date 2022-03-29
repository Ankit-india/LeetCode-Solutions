class Solution {
public:
    void fill(vector<vector<int>>&a, int s, int si, int n, int k)
    {
        if(s<0||s>=a.size()||si<0||si>=a[0].size()||a[s][si]==n||a[s][si]!=k)
            return;
        a[s][si]=n;
        fill(a,s,si+1,n,k);
        fill(a,s,si-1,n,k);
        fill(a,s+1,si,n,k);
        fill(a,s-1,si,n,k);        
    }
    vector<vector<int>> floodFill( vector<vector<int>>& image, int sr, int sc, int newColor) {
        fill(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
    
    
};