#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Helper {
protected:
    vi arrayInput(){
        int n;
        cin>>n;
        vi arr(n);
        loop(i, 0, n) cin>>arr[i];
        return arr;
    }
    vi arrayInput(int n){
        vi arr(n);
        loop(i, 0, n) cin>>arr[i];
        return arr;
    }
    string stringInput(){
        string s;
        cin>>s;
        return s;
    }
    void printArray(const vi &arr){
        for(int i=0; i<arr.size(); i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

struct Block {
    int l, r;
    int forced; // -1 free, 0 L, 1 R
};

class Solution : public Helper {
public:
    void solve(){
        int n;
        cin >> n;
        vi a = arrayInput(n);
        if (n == 0) {
            cout << 0 << endl;
            return;
        }
        vi delta(n - 1);
        bool is_valid = true;
        loop(i, 0, n - 1) {
            delta[i] = a[i + 1] - a[i];
            if (abs(delta[i]) > 1) is_valid = false;
        }
        if (!is_valid) {
            cout << 0 << endl;
            return;
        }
        vector<Block> blocks;
        int start = 0;
        loop(i, 0, n - 1) {
            if (delta[i] == 0) {
                Block b;
                b.l = start;
                b.r = i;
                if (b.l == b.r) {
                    b.forced = -1;
                } else {
                    int first_d = delta[b.l];
                    bool cons = true;
                    for (int j = b.l + 1; j < b.r; ++j) {
                        if (delta[j] != first_d) cons = false;
                    }
                    if (!cons) {
                        is_valid = false;
                    } else {
                        b.forced = (first_d == 1 ? 0 : 1);
                    }
                }
                blocks.pb(b);
                start = i + 1;
            }
        }
        Block b;
        b.l = start;
        b.r = n - 1;
        if (b.l == b.r) {
            b.forced = -1;
        } else {
            int first_d = delta[b.l];
            bool cons = true;
            for (int j = b.l + 1; j < b.r; ++j) {
                if (delta[j] != first_d) cons = false;
            }
            if (!cons) is_valid = false;
            else b.forced = (first_d == 1 ? 0 : 1);
        }
        blocks.pb(b);
        if (!is_valid) {
            cout << 0 << endl;
            return;
        }
        int m = blocks.size();
        ll mod = 676767677;
        ll ans = 0;
        int first_forced = blocks[0].forced;
        vector<int> possible_starts;
        if (first_forced != -1) {
            possible_starts.pb(first_forced);
        } else {
            possible_starts.pb(0);
            possible_starts.pb(1);
        }
        for (int s0 : possible_starts) {
            vector<int> states(m);
            states[0] = s0;
            bool ok = true;
            loop(bb, 1, m) {
                int required = 1 - states[bb - 1];
                states[bb] = required;
                if (blocks[bb].forced != -1 && blocks[bb].forced != required) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            ll total_r = 0;
            loop(bb, 0, m) {
                if (states[bb] == 1) {
                    total_r += (blocks[bb].r - blocks[bb].l + 1);
                }
            }
            int self = (states[0] == 0 ? 1 : 0);
            ll computed_a1 = self + total_r;
            if (computed_a1 == a[0]) {
                ans = (ans + 1) % mod;
            }
        }
        cout << ans << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}