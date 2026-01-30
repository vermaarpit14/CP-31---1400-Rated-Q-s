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
    int n; cin>>n;
    vector<int> a(n);
    rep(i, 0, n) cin>>a[i];
    int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0, neg = 0, cnt_p = 0, cnt_n = 0;
    int pos = -1;
    rep(i, 0, n){
        if(a[i] == 0) pos = i;
        cnt_0 += pos+1;
    }
    rep(i, 0, n){
        if(a[i] == 0) cnt_1 = 0, cnt_2 = 0, neg = 0;
        if(neg&1) cnt_2 += 1;
        else cnt_1 += 1;
        if(a[i] < 0) neg += 1;
        if(neg&1) cnt_p += cnt_2;
        else cnt_p += cnt_1;
    }
    cnt_n = ((n*(n+1)*1LL)>>1) - cnt_p - cnt_0;
    cout<<cnt_n<<" "<<cnt_p<<"\n";
    return 0;
}