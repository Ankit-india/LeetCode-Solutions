class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long int h_max=horizontalCuts[0];
        long int w_max=verticalCuts[0];
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for(int i = 0; i < horizontalCuts.size()-1; i++)
            h_max = horizontalCuts[i+1] - horizontalCuts[i] >  h_max ? horizontalCuts[i+1] - horizontalCuts[i] : h_max;
        for(int i = 0; i < verticalCuts.size()-1; i++)
            w_max = verticalCuts[i+1] - verticalCuts[i] >  w_max ? verticalCuts[i+1] - verticalCuts[i] : w_max;
			
		
        return (h_max * w_max) % MOD; 
    }
};