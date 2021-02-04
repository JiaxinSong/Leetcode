//全排列

class Solution {
public:
    vector<int> output;
    vector<int> printNumbers(int n) {
        if(n <= 0) return vector<int>(0);
        string s(n, '0');
        for(int i=0; i<=9; ++i)
        {
            s[0] = i + '0';
            permutation(s, s.length(), 1);
        }
        return output;
    }
    void permutation(string& s, int length, int pos)
    {
        // 这个函数的执行机制我想了好久才弄明白，mark一下，对带有循环的递归有时候还挺绕的
        if(pos == length)
        {
           inputNumbers(s);
           return; 
        }
        for(int i=0; i<=9; ++i)
        {
            s[pos] = i + '0';
            permutation(s, length, pos + 1);
        }
    }
    void inputNumbers(string s)
    {
        // 本函数与方法二的同名函数基本一样
        bool isUnwantedZero = true;
        string temp = "";
        for(int i=0; i<s.length(); ++i)
        {
            if(isUnwantedZero && s[i] != '0') isUnwantedZero = false;
            if(!isUnwantedZero) temp += s[i];
        }
        if(temp != "") output.push_back(stoi(temp)); // 如果 s = "000"，则temp会是空，stoi无法执行，会报错
    }
};

