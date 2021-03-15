class Solution {
public:
    vector<string>num1 = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
                        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen","Twenty"};
    vector<string>num2 = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    vector<string>num3 = {"Hundred","Thousand","Million","Billion"};//前面增加空字符串,方便单词数字与下标对应
    
    string numberToWords(int num) {
        if(num == 0)return "Zero";//单独考虑0
        string res = helper(num); 
        res.erase(0,1);
        return res; 
    }

    string helper(int num){
        if(num == 0){
            return "";
        }
        if(num<20){
            return " " + num1[num];
        }
        if(num<100){
            return " "+num2[num/10] + helper(num%10);
        }
        if(num < 1000){
            return helper(num/100)+" "+num3[0]+helper(num%100);
        }
        for(int i = 1; i <= 3; i++){
            if(num < pow(1000,i+1)){
                return helper(num/(int)pow(1000,i))+ " " + num3[i] + helper(num%(int)pow(1000,i));
            }
        }
        return "";
    }
};
