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

class Solution : public Helper {
private:
    static ll cost_to_make_block(const string& s, char ch) {
        vector<ll> pos;
        pos.reserve(s.size());
        for (ll i = 0; i < (ll)s.size(); ++i) if (s[i] == ch) pos.push_back(i);

        ll m = (ll)pos.size();
        if (m <= 1) return 0;
        
        vector<ll> t(m);
        for (ll i = 0; i < m; ++i) t[i] = pos[i] - i;

        ll med = t[m / 2];
        ll ans = 0;
        for (ll x : t) ans += llabs(x - med);
        return ans;
    }

public:
    void solve() {
        int n; 
        cin >> n;
        string s = stringInput();

        ll ans = min(cost_to_make_block(s, 'a'), cost_to_make_block(s, 'b'));
        cout << ans << "\n";
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