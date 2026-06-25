class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0;
        int tail = numbers.size()-1;
        while(head < tail)
        {
            auto sum = numbers[head]+numbers[tail];
            if(sum > target) tail--;
            else if(sum < target) head++;
            else return {head+1,tail+1};
        }
        return {};
    }
};
