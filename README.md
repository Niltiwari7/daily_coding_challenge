class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
      sort(begin(nums),end(nums));
      int mod = 1e9+7,cnt=0;
      vector<int>p(nums.size(),1);
      for(int i = 1;i<nums.size();i++)p[i] = p[i-1]*2%mod;
      int left = 0,right = nums.size()-1;
      while(left<=right){
          if(nums[left]+nums[right]>target){
              right--;
          }else{
              cnt+=p[right-left];
              cnt%=mod;
              left++;
          }
      }
      return cnt;
        
    }
};
