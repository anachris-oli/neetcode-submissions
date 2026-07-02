class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k==1) return nums;
        if(k==nums.size())
        {
            sort(nums.rbegin(),nums.rend());
            return {nums[0]};
        }
        
        map<int,int> elements_in_window;
        for(int i=0;i<k;i++)
        {
            elements_in_window[nums[i]]++;
        }

        vector<int> max_in_step;
        
        max_in_step.push_back(elements_in_window.rbegin()->first);
        int left=0;
        int right=k-1;
        while(right<(nums.size()-1))
        {
            elements_in_window[nums[left]]--;
            if(elements_in_window[nums[left]]<=0) elements_in_window.erase(nums[left]);
            left++;
            right++;
            elements_in_window[nums[right]]++;
            max_in_step.push_back(elements_in_window.rbegin()->first);

        }
        return max_in_step;

    }
};
