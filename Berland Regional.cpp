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
        int n; cin>>n;
        vector<int> u(n), s(n);
        rep(i, 0, n) cin>>u[i];
        rep(i, 0, n) cin>>s[i];
        vector<vector<int>> arr(n+1);
        rep(i, 0, n) arr[u[i]].pb(s[i]);
        rep(i, 1, n+1) sort(rall(arr[i]));
        rep(i, 1, n+1){
            rep(j, 1, sz(arr[i])) arr[i][j] += arr[i][j-1];
        }
        vector<int> ans(n, 0);
        rep(i, 0, n){
            int k = sz(arr[i+1]);
            rep(j, 0, k){
                ans[j] += (arr[i+1][((j+1)*(k/(j+1)))-1]);
            }
        }
        each(x, ans) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}