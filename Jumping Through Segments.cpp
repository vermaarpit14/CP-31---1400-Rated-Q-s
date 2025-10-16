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

bool valid_K(int n, vector<pair<int, int>> a, int k){
    pair<int, int> curr = {0, 0};
    rep(i, 0, n){
        curr.ff -= k;
        curr.ss += k;
        if((curr.ff > a[i].ss || curr.ss < a[i].ff)) return false;
        curr.ff = max(curr.ff, a[i].ff);
        curr.ss = min(curr.ss, a[i].ss);
    }
    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int, int>> a(n);
        rep(i, 0, n) cin>>a[i].ff>>a[i].ss;
        int low = 0, high = 1e9;
        int ans = 0;
        while(low <= high){
            int mid = low + ((high-low)>>2);
            if(valid_K(n, a, mid)) {
                ans = mid;
                high = mid-1;
            } else low = mid+1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}