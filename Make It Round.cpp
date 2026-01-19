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
        int n, m; cin>>n>>m;
        int y = n;
        int a = 0, b = 0;
        while(n%2 == 0){
            a += 1;
            n /= 2;
        }       
        while(n%5 == 0){
            b += 1;
            n /= 5;
        }
        int k = 1;
        while(a < b && k * 2 <= m) {
            k *= 2;
            a += 1;
        }
        while(b < a && k * 5 <= m) {
            k *= 5;
            b += 1;
        }
        while(k * 10 <= m) {
            k *= 10;
        }
        k *= (m/k);
        cout<<y * k<<"\n";
    }
    return 0;
}