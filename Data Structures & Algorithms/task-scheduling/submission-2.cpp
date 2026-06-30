class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> last_exec;   
        unordered_map<char,int> freq;             
        list<int> tasks_waiting;
        for(auto& t:tasks)
        {
            tasks_waiting.push_back(t);
            freq[t]++;
        }
        int cycle = 0;
        std::list<int>::iterator it = tasks_waiting.begin();
        
        while(!tasks_waiting.empty())
        {
            pair<int,std::list<int>::iterator> best_candidate={0,tasks_waiting.end()};
            for(auto it = tasks_waiting.begin(); it != tasks_waiting.end(); it++)
            {
                char t = *it;
                if(last_exec.count(t) == 0 || cycle>=(last_exec[t]+n+1))
                {
                    if(freq[t]>best_candidate.first) best_candidate = {freq[t],it};
                }
            }
            if(best_candidate.second!=tasks_waiting.end())
            {
                char t = *best_candidate.second;
                last_exec[t] = cycle;
                freq[t]--;
                tasks_waiting.erase(best_candidate.second);
            }
            cycle++;
        }
        return cycle;
    }
};

