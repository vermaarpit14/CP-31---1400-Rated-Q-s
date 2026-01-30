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

vector<int> parent, sz;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n, m; cin>>n>>m;
    parent.resize(n);
    rep(i, 0, n) parent[i] = i;
    sz.resize(n, 1);
    rep(i, 0, m){
        int k; cin>>k;
        if(k > 0){
            int first; cin>>first;
            first -= 1;
            rep(j, 1, k){
                int x; cin>>x;
                x -= 1;
                join(first, x);
            }
        }
    }
    rep(i, 0, n) cout<<sz[find(i)]<<" ";
    cout<<"\n";
    return 0;
}