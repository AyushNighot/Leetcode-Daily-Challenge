class Solution {
public:
    int dp[1001]={0};
    int minSteps(int n) {
        if (n==1) return 0;// edge case
        if (dp[n]!=0) return dp[n];
        int sqrtn=sqrt(n), factor=1;
        bool isPrime=1;
        for(int i=2; i<=sqrtn; i++){
            if (n%i==0){
                factor=i;
                isPrime=0;
                break;
            }
        }
        return dp[n]=(isPrime)?n:minSteps(factor)+minSteps(n/factor);
    }
};
