class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        int l = 0, r = 0, ans = 0, c = 0, cnt = 0;
        while (r < nums.size()) {
            c += nums[r];
            if (nums[r] == 1) {
                cnt = 0;
            }
            while (l <= r && c >= k) {
                if(c==k){
                    cnt++;
                }
                c -= nums[l];
                l++;
            }
            ans += cnt;
            r++;
        }
        return ans;
    }
};