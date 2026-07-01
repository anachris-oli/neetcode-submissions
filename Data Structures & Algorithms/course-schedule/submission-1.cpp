class Solution {
public:
    unordered_map<int,vector<int>> list_prereq_per_course;


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto rows = prerequisites.size();
        for(int i=0;i<rows;i++)
        {
            list_prereq_per_course[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++)
        {   unordered_set<int> listing;
            if(!dfs(i,listing)) return false;
        }
        return true;
    }

    bool dfs(int course,unordered_set<int>& listing)
    {
        if(listing.count(course)>0) return false;
        if(list_prereq_per_course[course].empty()) return true;

        listing.insert(course);
        for(auto req : list_prereq_per_course[course])
        {
            if(!dfs(req,listing)) return false;
        }
        listing.erase(course);
        list_prereq_per_course[course].clear();
        return true;
    }   
};
