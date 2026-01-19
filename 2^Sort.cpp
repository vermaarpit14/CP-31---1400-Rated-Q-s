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
        int n, k; cin>>n>>k;
        vector<int> a(n), b(n, 0);
        rep(i, 0, n) cin>>a[i];
        rep(i, 0, n-1){
            if(a[i] < 2*a[i+1]) b[i] = 1;
        }
        int ans = 0, cnt = 0;
        rep(i, 0, n){
            if(b[i] == 0){
                ans += max(0LL, cnt-k+1);
                cnt = 0;
            } else cnt += 1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}