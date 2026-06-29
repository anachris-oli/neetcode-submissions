class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<double,vector<vector<int>>> dist_map;
        for(const auto& el : points)
        {
            double distance = sqrt(pow(el[0],2) + pow(el[1],2));
            dist_map[distance].push_back(el);
        }
        vector<vector<int>> result;
        for (auto it = dist_map.begin(); it != dist_map.end(); ++it) 
        {
            while(it->second.size()>0)
            {
                result.push_back(it->second.back());
                it->second.pop_back();
                if(result.size()==k) return result;
            }
        }
        
    }
};
