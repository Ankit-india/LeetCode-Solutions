class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0"){
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> temp(n1 + n2, 0);
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                int k = (num1[i] - '0') * (num2[j] - '0');
                temp[i + j] += k;
                temp[i + j + 1] += temp[i + j] / 10;
                temp[i + j] %= 10;
            }
        }
        reverse(temp.begin(), temp.end());
        int z = 0;
        while (z < temp.size() && temp[z] == 0)
        {
            z++;
        }
        string s = "";
        for (int i = z; i < temp.size(); i++)
        {
            s += to_string(temp[i]);
        }
        return s;
    }
};