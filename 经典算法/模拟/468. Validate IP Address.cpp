class Solution {
public:
    string validIPAddress(string IP) {
        int pos1 = IP.find('.'); //寻找字符串中第一个"."的位置
        int pos2 = IP.find(':'); //寻找字符串中第一个":"的位置
        //字符串中 "." 和 ":" 不能共存，否则不合法
        if ((pos1 == IP.npos and pos2 != IP.npos) or (pos1 != IP.npos and pos2 == IP.npos)) {
            string pattern = (pos1 != IP.npos) ? "." : ":";
            IP += pattern;
            int pos = IP.find(pattern);
            int cnt = 0;
            while (pos != IP.npos) {
                string temp = IP.substr(0, pos);
                if (pattern == ".") {
                    if (cnt >= 4 or temp.length() >= 4 or temp.length() == 0) return "Neither";
                    for (auto &c:temp) {
                        if (!isdigit(c)) return "Neither";
                    }
                    int x = stoi(temp);
                    if (to_string(x) != temp) return "Neither";
                    if (x < 0 or x >= 256) {
                        return "Neither";
                    }
                } else {
                    if (cnt >= 8 or temp.length() >= 5 or temp.length() == 0) return "Neither";
                    for (auto &c:temp) {
                        if (!isxdigit(c)) return "Neither";
                    }
                }
                cnt++;
                IP = IP.substr(pos + 1, IP.size());
                pos = IP.find(pattern);
            }
            if (pattern == ".") {
                return (cnt == 4) ? "IPv4" : "Neither";
            } else {
                return (cnt == 8) ? "IPv6" : "Neither";
            }
        }
        return "Neither";
    }
};
