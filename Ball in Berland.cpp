/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int a, b, k; cin>>a>>b>>k;
        vector<int> A(a), B(b);
        rep(i, 0, k){
            int x; cin>>x;
            A[x-1] += 1;
        }
        rep(i, 0, k){
            int x; cin>>x;
            B[x-1] += 1;
        }
        int ans = 1LL*k*(k-1)/2;
        rep(i, 0, a) ans -= A[i]*(A[i]-1)/2;
        rep(i, 0, b) ans -= B[i]*(B[i]-1)/2;
        cout<<ans<<"\n";
    }
    return 0;
}