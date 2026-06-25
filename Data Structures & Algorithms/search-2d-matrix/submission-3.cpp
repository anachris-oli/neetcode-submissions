class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int head_v = 0;
        int tail_v = matrix.size()-1;

        if(tail_v>0){
            while(head_v<tail_v)
            {
                auto mid = head_v+(tail_v-head_v)/2;
                if(matrix[mid][0]>target)
                {
                    if(mid>1 and matrix[mid-1][0]<target)
                    {
                        head_v = mid-1;
                        break;
                    }
                    tail_v = mid-1;
                }
                else if(matrix[mid][0]<target)
                {
                    if(mid<matrix.size()-1 and matrix[mid+1][0]>target)
                    {
                        head_v = mid;
                        break;
                    }
                    head_v = mid+1;
                }
                else return true;
            }
        }

        int head_h = 0;
        int tail_h = matrix[head_v].size()-1;

        if(tail_h>0){
            while(head_h<tail_h)
            {
                auto mid = head_h+(tail_h-head_h)/2;
                if(matrix[head_v][mid]>target) tail_h = mid-1;
                else if(matrix[head_v][mid]<target) head_h = mid+1;
                else return true;
            }
        }
        return matrix[head_v][head_h]==target;
        
    }
};
