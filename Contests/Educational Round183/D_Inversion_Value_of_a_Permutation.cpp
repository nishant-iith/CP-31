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

vector<map<int, vector<int>>> parts(31);

void gen(int nn, int rem, int min_l, int cur_g, vector<int> curr) {
    if (rem == 0) {
        if (parts[nn].find(cur_g) == parts[nn].end()) {
            parts[nn][cur_g] = curr;
        }
        return;
    }
    for (int l = min_l; l <= rem; l++) {
        curr.pb(l);
        gen(nn, rem - l, l, cur_g + l * (l - 1) / 2, curr);
        curr.pop_back();
    }
}

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

class Solution : public Helper {
public:
    void solve(){
        int n, k;
        cin >> n >> k;
        int T = n * (n - 1) / 2;
        int tg = T - k;
        auto it = parts[n].find(tg);
        if (it == parts[n].end()) {
            cout << 0 << endl;
        } else {
            vi lengths = it->second;
            vi perm;
            int cur = n;
            for (int len : lengths) {
                for (int j = cur - len + 1; j <= cur; j++) {
                    perm.pb(j);
                }
                cur -= len;
            }
            for (int x : perm) cout << x << " ";
            cout << endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int nn = 2; nn <= 30; nn++) {
        vector<int> emp;
        gen(nn, nn, 1, 0, emp);
    }
    int t;
    cin>>t;
    while(t--){
        Solution sol;
        sol.solve();
    }
    return 0;
}