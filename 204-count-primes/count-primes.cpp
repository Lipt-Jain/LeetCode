class Solution {
public:
    vector<int> getSieve(int N) {
        vector<int> prime(N + 1, 1);

        prime[0] = prime[1] = 0;

        for (int i = 2; i * i <= N; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= N; j += i)
                    prime[j] = 0;
            }
        }

        return prime;
    }
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<int> prime=getSieve(n-1);
        int cnt=0;
        for(int i=2;i<n;i++){
            cnt+=prime[i];
            prime[i]=cnt;
        }
        return prime[n-1];
    }
};