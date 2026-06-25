class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<1) return 0;
        if(s.length()==1) return 1;
        int max_length = 0;
        int head = 0;
        int tail = head+1;
        unordered_map<char,int> last_seen;

        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if(last_seen.count(c)>0 and last_seen[c]>=head)
            {
                head = last_seen[c]+1;
            }
            last_seen[c] = i;
            max_length = max(max_length,i-head+1);

        }
        return max_length;
    }
};
