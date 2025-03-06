#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll MOD = 998244353;
 
// fast modular exponentiation
ll modexp(ll base, ll exp, ll mod){
    ll result = 1 % mod;
    base %= mod;
    while(exp > 0){
        if(exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int k;
        ll n;
        cin >> k >> n;
 
        // Special case: if k==1, only x=1 exists and the only valid arrays are those of ones.
        if(k == 1){
            cout << (n % MOD) << "\n";
            continue;
        }
 
        // Maximum possible number of non‐one factors (core factors) possible is R,
        // where 2^R <= k.
        int R = 0;
        while((1LL << (R+1)) <= k)
            R++;
 
        // We will compute G[r][x] for 0 <= r <= R and 1 <= x <= k.
        // G[r][x] = number of ordered factorizations of x using exactly r factors (each >= 2).
        // Initialize: G[0][1] = 1; and G[0][x] = 0 for x > 1.
        vector<vector<ll>> G(R+1, vector<ll>(k+1, 0));
        G[0][1] = 1;
 
        // For r from 1 to R, update using:
        // For each y and each d from 2 to floor(k/y): x = d*y gets an additional G[r-1][y].
        for (int r = 1; r <= R; r++){
            for (int y = 1; y <= k; y++){
                if(G[r-1][y] != 0){
                    int max_d = k / y;
                    for (int d = 2; d <= max_d; d++){
                        int x = d * y;
                        G[r][x] = (G[r][x] + G[r-1][y]) % MOD;
                    }
                }
            }
        }
 
        // Precompute the insertion multipliers.
        // For a core factorization with r >= 1 factors, the number of ways to insert ones (so that total length is between 1 and n)
        // is binom(n+1, r+1) mod MOD.
        // (For r = 0, the answer is simply n, because arrays of all ones of length 1...n are n in number.)
        vector<ll> C(R+1, 0);
        for (int r = 1; r <= R; r++){
            int rPlus = r + 1;
            ll numer = 1;
            for (int i = 0; i < rPlus; i++){
                ll term = ((n + 1 - i) % MOD + MOD) % MOD;
                numer = (numer * term) % MOD;
            }
            ll fact = 1;
            for (int i = 1; i <= rPlus; i++){
                fact = (fact * i) % MOD;
            }
            ll invfact = modexp(fact, MOD - 2, MOD);
            C[r] = (numer * invfact) % MOD;
        }
 
        // Now, for each x from 1 to k, compute the answer.
        // For x = 1: only possibility is an array of ones: count = n.
        // For x >= 2: 
        //   answer[x] = sum_{r>=1} G[r][x] * binom(n+1, r+1).
        vector<ll> ans(k+1, 0);
        ans[1] = n % MOD;
        for (int x = 2; x <= k; x++){
            ll total = 0;
            for (int r = 1; r <= R; r++){
                total = (total + (G[r][x] * C[r]) % MOD) % MOD;
            }
            ans[x] = total % MOD;
        }
 
        // Output the answers for x=1,2,...,k.
        for (int x = 1; x <= k; x++){
            cout << ans[x] % MOD << (x < k ? " " : "\n");
        }
    }
    return 0;
}
