class Solution {
public:
    int countPrimes(int n) {
        // This is Sieve of Eratosthenes solution
        if(n <= 1) return 0;
        int prime_count = 0;
        vector<bool> primes (n, true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i*i < n; i++){
            if(primes[i]){
                for(int j = i*i; j < n; j+=i)
                    primes[j] = false;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(primes[i])
                prime_count++;
        }    
        return prime_count;
        /*
        This solution exceeds the time limit
        
        if(n <= 2) return 0;
        vector<int> primes;
        primes.push_back(2);
        for(int i = 2; i < n; i++){
            for(int j = 0; j < primes.size(); j++){
                if(i % primes[j] == 0)
                    break;
                if(j == primes.size() - 1)
                    primes.push_back(i);
            }
        }
        return primes.size();
        */
    }
};