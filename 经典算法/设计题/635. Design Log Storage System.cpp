class LogSystem {
public:
    LogSystem() 
    {
        datas.clear();  
    }
    
    void put(int id, string timestamp) 
    {
        // 使用timestamp作为key可以天然的保证map中的数据是从小到大排列的
        datas[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string granularity) 
    {
        vector<int>res;
        int len = 0;
        
        if (granularity == "Year") {
            len = 4;
        } else if (granularity == "Month") {
            len = 7;
        } else if(granularity == "Day") {
            len = 10;
        } else if(granularity == "Hour"){
            len = 13;
        } else if(granularity == "Minute"){
            len = 16;
        } else if(granularity == "Second"){
            len = 19;
        }
        string s_str=s.substr(0, len);
        string e_str=e.substr(0, len);

        for(auto &it : datas){
            if((it.first).substr(0,len) < s_str){
                continue;
            }
            if((it.first).substr(0,len) > e_str){
                break;
            }
            res.push_back(it.second);
        }
        return res;
    }

private:
    std::map<string, int> datas;
};



/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */
