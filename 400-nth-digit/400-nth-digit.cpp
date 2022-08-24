class Solution {
public:
    int findNthDigit(int n) {
        long long minNum = 1, maxNum = 9, digitNum = 1;
        while (n > (maxNum - minNum + 1) * digitNum) {
            n -= (maxNum - minNum + 1) * digitNum;
            minNum *= 10;
            maxNum = maxNum * 10 + 9;
            ++ digitNum;
        }
        long long num = minNum + (n - (n % digitNum == 0 ? digitNum : n % digitNum)) / digitNum;
        n -= (num - minNum) * digitNum;
        n = digitNum - n;
        while (n --) num /= 10;
        return num % 10;
    }
};