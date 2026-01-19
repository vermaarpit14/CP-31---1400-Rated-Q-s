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

int f(vector<int> &a){
    int k = sz(a);
    sort(rall(a));
    int x = k-1, sum = 0;
    rep(i, 0, k){
        sum += 1LL*x*(a[i]);
        x -= 2;
    }
    return sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n, m; cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    int mx = 0;
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>arr[i][j];
            arr[i][j] -= 1;
            mx = max(mx, arr[i][j]);
        }
    }
    vector<vector<int>> X(mx+1), Y(mx+1);
    rep(i, 0, n){
        rep(j, 0, m){
            X[arr[i][j]].pb(i);
            Y[arr[i][j]].pb(j);
        }
    }
    int ans = 0;
    rep(i, 0, mx+1){
        ans += f(X[i]);
        ans += f(Y[i]);
    }
    cout<<ans<<"\n";
    return 0;
}