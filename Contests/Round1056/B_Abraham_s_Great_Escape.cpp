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

static inline char dir_to(int r1, int c1, int r2, int c2) {
    if (r2 == r1 - 1 && c2 == c1) return 'U';
    if (r2 == r1 + 1 && c2 == c1) return 'D';
    if (c2 == c1 - 1 && r2 == r1) return 'L';
    if (c2 == c1 + 1 && r2 == r1) return 'R';
    return 'U';
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
    void solve() {
        int n;
        long long k;
        if (!(cin >> n >> k)) return;

        ll total = 1LL * n * n;
        ll m = total - k;

        if (m == 1) {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";

        vector<pair<int,int> > cells;
        cells.reserve(n * n);
        for (int r = 0; r < n; ++r) {
            if ((r & 1) == 0) {
                for (int c = 0; c < n; ++c) cells.push_back(make_pair(r, c));
            } else {
                for (int c = n - 1; c >= 0; --c) cells.push_back(make_pair(r, c));
            }
        }

        vector<string> grid(n, string(n, 'U'));

        if (k > 0) {
            int r0 = cells[0].first, c0 = cells[0].second;
            grid[r0][c0] = 'U'; // immediate exit

            for (ll i = 1; i < k; ++i) {
                int r = cells[i].first,  c  = cells[i].second;
                int pr = cells[i-1].first, pc = cells[i-1].second;
                grid[r][c] = dir_to(r, c, pr, pc);
            }
        }

        ll i = k;
        if ((m & 1LL) == 1) {
            int r1 = cells[i].first,   c1 = cells[i].second;
            int r2 = cells[i+1].first, c2 = cells[i+1].second;
            grid[r1][c1] = dir_to(r1, c1, r2, c2);
            ++i; // m-1 is even now
        }
        while (i + 1 < total) {
            int r1 = cells[i].first,   c1 = cells[i].second;
            int r2 = cells[i+1].first, c2 = cells[i+1].second;
            grid[r1][c1] = dir_to(r1, c1, r2, c2);
            grid[r2][c2] = dir_to(r2, c2, r1, c1);
            i += 2;
        }

        for (int r = 0; r < n; ++r) cout << grid[r] << '\n';
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