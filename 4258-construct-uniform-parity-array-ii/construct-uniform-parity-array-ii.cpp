class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

  int n = nums1.size();
    
        int mini =*min_element(nums1.begin(),nums1.end());

        bool odd = false;

        for(int i =0 ;i<=n-1;i++)
            {
                if(nums1[i]%2==1) odd =true;
            }

        if(mini%2==0 && odd) return false; 
        return true;
    }
    
};