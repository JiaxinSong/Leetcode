class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans; //储存答案
        string str; //临时的一个string的variable
        vector<int> index; //储存需要插入空格的位置
        for(int i = 0; i < words.size(); ++i)
        {
            //当加上这个单词小于maxWidth时我们可以加上这个word，然后将此时word在str里的index
            //储存进index vector， 然后注意我们要添加一个" "为下一个word做准备
            if(str.size() + words[i].size() < maxWidth)
            {
                str += words[i];
                index.push_back(str.size());
                str += ' ';
            }
            //当长度正好时我们就可以直接加上这个word然后push进ans
            //注意我们要将str 还有 index vector还原，因为我们要到下一行了
            else if(str.size() + words[i].size() == maxWidth)
            {
                str += words[i];
                ans.push_back(str);
                str = "";
                index.clear();
            }
            //这个else说明此时的str加上这个word[i]已经超过了maxWidth(此时还没有加上word[i]))
            else
            {
                //先计算出我们需要多少个额外的" "。
                int space = maxWidth - str.size();
                //如果只有一个word在str里说明我们什么也不用做
                //反之如果有一个以上的话我们就需要先将word[i-1]添加的" "给erase
                //因为此时word[i-1]会变成最后的字符，所以我们不需要给word[i-1]添加" "
                //所以我们将他的index移除， 然后需要加上额外的被erase的那个" "
                if(index.size() > 1)
                {
                    str.erase(index.back(), 1);
                    index.pop_back();
                    space++;
                }
                //开始计算平均每个字符间需要多少个" "
                //x代表平均的" "，剩下没分配完的 " "给到y,然后给前面的y个word额外加1个" "
                int x = 0, y = 0;
                if(!index.empty())
                {
                    x = space/index.size();
                    y = space%index.size();
                }
                for (int j = index.size()-1; j >= 0; j--)
                    str.insert(index[j], string(x + (j < y ? 1 : 0), ' '));
                ans.push_back(str);
                //还原
                str = "";
                index.clear();
                //注意这里我们没有加上word[i]所以我们要将i decrement重新讨论
                --i;
            }
        }
        //最后一行扫尾
        if(!str.empty())
        {
            if(str.size() < maxWidth)
                str += string(maxWidth - str.size(), ' ');
            ans.push_back(str);
        }
        return ans;
    }
};

