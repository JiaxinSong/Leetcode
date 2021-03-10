class Solution {
public:
    int calculate(string s) {
        char    sign    = '+';
        int     num     = 0;    
        vector<int> v;

        for(int idx = 0 ; idx < s.size(); ++idx)
        {
            char c = s[idx];            
            if(  isdigit( c ) ){ num = 10*num + ( c - '0'); }
            if( (!isdigit(c) && c != ' ') || idx == s.size() - 1){
                if( sign == '+' ){ v.push_back(+num); }
                if( sign == '-' ){ v.push_back(-num); }
                if( sign == '*' ){ int tmp = v.back()*num;  v.pop_back();   v.push_back(tmp); }
                if( sign == '/' ){ int tmp = v.back()/num;  v.pop_back();   v.push_back(tmp); }                
                sign    = c;
                num     = 0;
            }
        }

        int result = 0;
        for( auto num : v ){ result += num; }
        return result;
    }
};

