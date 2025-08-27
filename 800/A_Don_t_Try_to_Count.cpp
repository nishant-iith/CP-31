#include<bits/stdc++.h>
using namespace std;

//type names
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// macros
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Solution {
    private:
        vi arrayInput(){
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }
        string stringInput(){
            string s;
            cin>>s;
            return s;
        }

    public:
        bool check(string &s, string &x){
            int n = s.size();
            int m = x.size();

            if(m < n) return false;
            loop(i, 0, m - n + 1) {
                if(s == x.substr(i, n)) return true;
            }
            return false;
        }
        void solve(){
            // Your code here
            int n, m;
            cin>>n>>m;
            string x = stringInput();
            string s = stringInput();

            string x0 = x; // 0 operations
            string x1 = x0 + x0; // 1 operations
            string x2 = x1 + x1; // 2 operations
            string x3 = x2 + x2; // 3 operations
            string x4 = x3 + x3; // 4 operations
            string x5 = x4 + x4; // 5 operations

            ll answer = -1;
            if(check(s, x0)) answer = 0;
            else if(check(s, x1)) answer = 1;
            else if(check(s, x2)) answer = 2;
            else if(check(s, x3)) answer = 3;
            else if(check(s, x4)) answer = 4;
            else if(check(s, x5)) answer = 5;

            cout<<answer<<"\n";
        }
};

int main(){
    // fast input output
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