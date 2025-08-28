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

class Helper {
    private:
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
            int n;
            int k;
            cin >> n >> k;
            string s;
            cin >> s;

            int max_consecutive_ones = 0;
            int current_consecutive_ones = 0;
            for (char c : s) {
                if (c == '1') {
                    current_consecutive_ones++;
                } else {
                    max_consecutive_ones = max(max_consecutive_ones, current_consecutive_ones);
                    current_consecutive_ones = 0;
                }
            }
            max_consecutive_ones = max(max_consecutive_ones, current_consecutive_ones);

            if (max_consecutive_ones >= k) {
                cout << "NO" << endl;
                return;
            }
            cout << "YES" << endl;
            
            vi p(n);
            int current_val = 1;
            loop(i, 0, n) {
                if(s[i] == '1') {
                    p[i] = current_val++;
                }
            }
            loop(i, 0, n) {
                if(s[i] == '0') {
                    p[i] = current_val++;
                }
            }

            loop(i, 0, n) {
                cout << p[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
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