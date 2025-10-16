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
        vector<int> a(n);
        rep(i, 0, n) cin>>a[i];
        if(k >= 3){
            cout<<0<<"\n";
            continue;
        }
        vector<int> diff;
        rep(i, 0, n){
            rep(j, i+1, n) diff.pb(abs(a[i]-a[j]));
        }
        sort(all(diff));
        int mn = min(*min_element(all(a)), diff[0]);
        if(k == 1) cout<<mn<<"\n";
        else{
            rep(i, 0, n){
                int lb = lower_bound(all(diff), a[i]) - diff.begin();
                if(lb < sz(diff))mn = min(mn,abs(diff[lb] - a[i]));
                if(lb > 0) mn = min(mn, abs(a[i] - diff[lb-1]));
            }
            cout<<mn<<"\n";
        }
    }
    return 0;
}