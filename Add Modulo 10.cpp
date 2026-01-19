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
        vector<int> a(n);
        bool all_equal = true;
        rep(i, 0, n) cin>>a[i];
        rep(i, 1, n) {
            if(a[i-1] != a[i]){
                all_equal = false;
                break;
            }
        }
        if(all_equal){
            cout<<"Yes"<<"\n";
            continue;
        }
        bool has_zero = false;
        rep(i, 0, n){
            if(a[i]&1) a[i] += a[i]%10;
            if(a[i]%10 == 0) has_zero = true;
        }
        if(has_zero){
            bool f = true;
            rep(i, 1, n){
                if(a[i-1] != a[i]){
                    f = false;
                    break;
                }
            }
            cout<<(f ? "Yes" : "No")<<"\n";
            continue;
        }
        rep(i, 0, n){
            while(a[i]%10 != 2) a[i] += a[i]%10;
        }
        bool ans = true;
        rep(i, 1, n){
            if((a[i-1]%20) != (a[i]%20)){
                ans = false;
                break;
            }
        }
        cout<<(ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}