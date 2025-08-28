#include<bits/stdc++.h>
using namespace std;

//type names
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

// macros
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Helper {
    public:
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
};

class Solution : public Helper {
    public:
        void solve(){
            vi a = arrayInput();
            int n = a.size();
            vi dp(n + 1, 0);
            vector<vi> positions(n + 1);

            loop(i, 1, n + 1) {
                dp[i] = dp[i-1];
                int current_val = a[i-1];
                int current_idx = i-1;

                positions[current_val].pb(current_idx);

                int count_of_val = positions[current_val].size();
                int block_size_needed = current_val;
                if (count_of_val >= block_size_needed) {
                    int first_elem_idx = positions[current_val][count_of_val - block_size_needed];
                    int prev_lns_length = dp[first_elem_idx];
                    int new_length = prev_lns_length + block_size_needed;
                    
                    dp[i] = max(dp[i], new_length);
                }
            }

            cout << dp[n] << endl;
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