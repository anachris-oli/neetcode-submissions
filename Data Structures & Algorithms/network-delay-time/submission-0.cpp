class Solution {
    unordered_map<int,vector<pair<int,int>>> node_targets;
    vector<int> visited_at; //INT_MAX represents node not visited
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        for(auto t:times)
        {
            node_targets[t[0]].push_back({t[1],t[2]});
        }

        visited_at = vector<int>(n,INT_MAX);
        visited_at[k-1]=0;
        dfs(k,0);
        sort(visited_at.rbegin(), visited_at.rend());

        return visited_at[0] == INT_MAX ? -1 : visited_at[0];


    }

    void dfs(int node,int time_arrival)
    {
        if(node_targets.count(node)>0)
        {
            for(auto it=node_targets[node].begin();it!=node_targets[node].end();++it)
            {
                auto target_pair = *it;
                int time_to_node = target_pair.second;
                int target_node = target_pair.first;
                int target_arrival = time_arrival+time_to_node;
                if(target_arrival<visited_at[target_node-1])
                {
                    visited_at[target_node-1] = target_arrival;
                    dfs(target_node,target_arrival);
                }
            }
        }
        return;
    }
};
