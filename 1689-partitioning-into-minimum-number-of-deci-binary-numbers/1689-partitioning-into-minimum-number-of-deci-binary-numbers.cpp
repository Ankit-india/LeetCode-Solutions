class Solution {
public:
    int minPartitions(string n) {
          char answer = '1';
        
        for (auto current : n)
            if (current > answer){
                answer = current;
                if (answer == '9') break;
            }
        
        return answer - 0x30;
    }
};