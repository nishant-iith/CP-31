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
        bool is_half_possible(ll goals1, ll goals2) {
            if (goals1 < 0 || goals2 < 0) return false;
            
            ll L = max(goals1, goals2);
            ll S = min(goals1, goals2);

            if (L > 2 * (S + 1)) {
                return false;
            }
            return true;
        }

        void solve(){
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            
            bool first_half_ok = is_half_possible(a, b);
            
            bool second_half_ok = is_half_possible(c - a, d - b);

            if (first_half_ok && second_half_ok) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
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

/**
 * Avoid mistakes when calculating the goals for each half.
 * L / (S + 1) > 2 is actually equivalent to L > 2 * (S + 1) for integers but be careful with division.
 * To avoid division altogether, you can rearrange the condition to L > 2 * (S + 1).
 */