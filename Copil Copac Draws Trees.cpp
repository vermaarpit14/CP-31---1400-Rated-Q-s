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

void f(int v, int p, vector<vector<int>> &adj, vector<int> &dp, map<pair<int, int>, int> &idx){
    each(c, adj[v]){
        if(c == p) continue;
        if(idx[{p, v}] < idx[{v, c}]) dp[c] = dp[v];
        else dp[c] = 1 + dp[v];
        f(c, v, adj, dp, idx);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> adj(n+1);
        vector<int> dp(n+1, 1);
        map<pair<int, int>, int> idx;
        rep(i, 0, n-1){
            int u, v; cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
            idx[{u, v}] = i;
            idx[{v, u}] = i;
        }
        idx[{0, 1}] = -1;
        f(1, 0, adj, dp, idx);
        cout<<*max_element(all(dp))<<"\n";
    }
    return 0;
}