class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()==0) return {};

        unordered_map<char,int> t_map;
        for(const auto& c:t)
        {  
            t_map[c]++;
        }
        
        int window_length = INT_MAX;
        int head =0;
        int tail =0;

        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int> s_map;
            for(int j=i;j<s.length();j++)
            {
                auto c=s[j];
                s_map[c]++;

                bool found_all = true;
                for(const auto& [key,val]:t_map)
                {
                    if((s_map.count(key)==0 or s_map[key]<val))
                    {   
                        found_all = false;
                        break;
                    }
                }
                if(found_all and j-i+1 < window_length)
                {
                    head = i;
                    tail = j;
                    window_length = j-i+1;
                }
                
            }
        }
        return window_length==INT_MAX ? "" : s.substr(head, tail-head+1);
    }
};
