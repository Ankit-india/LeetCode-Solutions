// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        
        int t = Integer.parseInt(sc.next());
        while(t>0)
        {
            int n = Integer.parseInt(sc.next());
            Solution T = new Solution();
            List<String> ans = T.AllParenthesis(n);
            String[] sequences = ans.toArray(new String[0]);
            Arrays.sort(sequences);
            int k = sequences.length;
            for(int i=0;i<k;i++)
            {
                System.out.println(sequences[i]);
            }
            
            t--;
            
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution {
    
    public List<String> AllParenthesis(int n) 
    {
        // Write your code here
        List<String> ans = new LinkedList<>();
        solve(n,n, new StringBuilder(), ans);
        return ans;
    }
    
    public void solve(int o, int c, StringBuilder op, List<String> res){
        if(o == 0 && c == 0){
            res.add(op.toString());
            return;
        }
        
        if(o != 0){
            StringBuilder temp = new StringBuilder(op);
            temp.append('(');
            solve(o-1, c, temp, res);
        }
        if(c > o){
            StringBuilder temp = new StringBuilder(op);
            temp.append(')');
            solve(o, c-1, temp, res);
        }
    }
}