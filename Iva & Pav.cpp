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
        vector<vector<int>> pre(n, vector<int>(31, 0));
        rep(i, 0, n) {
            cin>>a[i];
            rep(j, 0, 31){
                int x = (a[i] >> j) & 1;
                pre[i][j] = x + (i>0 ? pre[i-1][j] : 0);
            }
        }
        int q; cin>>q;
        while(q--){
            int l, k; cin>>l>>k;
            l--;
            int r = -1;
            int low = l, high = n-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                int sum = 0;
                rep(i, 0, 31){
                    if(pre[mid][i]-(l>0 ? pre[l-1][i] : 0) == mid-l+1) sum += (1LL << i);
                }
                if(sum >= k){
                    r = mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            cout<<(r!=-1 ? r+1 : r)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}