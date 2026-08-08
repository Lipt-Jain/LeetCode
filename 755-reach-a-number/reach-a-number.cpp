class Solution {
public:
    int reachNumber(int target) {
        int n=1;
        int sum=1;
        if(target==0 || target==1 || target==-1){
            return abs(target);
        }
        while(abs(target)>sum){
            n++;
            sum=(n*(n+1))/2;
            if(abs(target)==sum){
                return n;
            }
        }
        while((sum-abs(target))%2!=0){
            n++;
            sum=(n*(n+1))/2;
        }
        return n;
    }
};