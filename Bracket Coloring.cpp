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
        string s; cin>>s;
        int cnt = 0;
        bool poss = true;
        each(ch, s){
            if(ch == '(') cnt += 1;
            else cnt -= 1;
            if ((s[0] == '(' && cnt < 0) || (s[0] == ')' && cnt > 0)) poss = false;
        }
        if(cnt != 0){
            cout<< -1 <<"\n";
            continue;
        }
        if(poss){
            cout<<1<<"\n";
            vector<int> ans(n, 1);
            each(x, ans) cout<<x<<" ";
            cout<<"\n";
        } else {
            cout<<2<<"\n";
            int cnt = 0;
            vector<int> ans;
            int cnt1 = 0, cnt2 = 0;
            each(ch, s) {
                if (ch == '(') cnt += 1;
                else cnt -= 1;
                if(cnt > 0) {
                    ans.pb(1);
                    cnt1 += 1;
                } else if(cnt < 0) {
                    ans.pb(2);
                    cnt2 += 1;
                } else {
                    if(cnt1&1){
                        ans.pb(1);
                        cnt1 += 1;
                    } else {
                        ans.pb(2);
                        cnt2 += 1;
                    }
                }
            }
            each(x, ans) cout<<x<<" ";
            cout<<"\n";
        }
    }
    return 0;
}