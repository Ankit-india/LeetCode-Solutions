class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(),courses.end(),comp);
        priority_queue<int> p;
        int MaxTime = 0;
        for(auto i : courses) {
            MaxTime += i[0];
            p.push(i[0]);
            if(MaxTime > i[1]) {
                MaxTime -= p.top();
                p.pop();
            }
        }
        return p.size();
    }
};