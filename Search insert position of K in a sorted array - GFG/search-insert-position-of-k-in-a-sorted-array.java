//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int Arr[]= new int[N];
            for(int i = 0; i < N; i++)
                Arr[i] = Integer.parseInt(input_line[i]);
            int k = Integer.parseInt(read.readLine());
            
            Solution ob = new Solution();
            System.out.println(ob.searchInsertK(Arr, N, k));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    static int binarySearchForThisQuestion(int arr[], int k) {
        if(k > arr[arr.length - 1]) return arr.length;
        
        int start = 0;
        int end = arr.length - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            if(k < arr[mid]) end = mid-1;
            else if (k > arr[mid]) start = mid + 1;
            else {
                return mid;
            }
        }
        return start;
    }
    static int searchInsertK(int arr[], int n, int k)
    {
        // code here
        int ans = binarySearchForThisQuestion(arr, k);
        return ans;
    }
}