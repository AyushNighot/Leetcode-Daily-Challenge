class Solution {
public:
    int pivotInteger(int n) {
        if( n == 1 ) return 1;
        int allsum = 0;
        int pivotal = 0;
        for(int i = 0; i <= n; i++)  
       {  
          allsum = allsum + i;  
       } 

        while (n > 0)
        {        
            pivotal = pivotal + n;
             
            if(pivotal == allsum)
            {
                return n;
            }
            allsum = allsum - n;

            n--;
        }
        return -1;
    }
};
