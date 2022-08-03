class MyCalendar {
    map<int,int> arr;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto x = arr.upper_bound(start);
        if(x == arr.end() || end<= x->second) {
            arr[end]=start;
            return true;
        } 
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */