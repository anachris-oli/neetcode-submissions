class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for(int i=0; i<strs.size();i++)
        {
            auto ordered_string = strs[i];
            sort(ordered_string.begin(),ordered_string.end());
            map[ordered_string].push_back(strs[i]);
        }
        for(auto it : map)
        {
            result.push_back(it.second);
        }
        return result;
    }
};
