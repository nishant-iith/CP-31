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

/**
 * Problem: YunQian starts at (a,b) and wants to reach (c,d).
 * Moves allowed:
 *   - (x,y) -> (x+1,y+1)  (top-right diagonal)
 *   - (x,y) -> (x-1,y)    (left)
 *
 * Task: Find minimum moves to reach (c,d) or -1 if impossible.
 *
 * Input: t test cases
 *        Each test case: integers a, b, c, d
 * Output: Minimum moves or -1 if not possible
 */


class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            ll x0, y0, x, y;
            cin>>x0>>y0>>x>>y;

            ll dy = abs(y - y0);
            x0 = x0 + dy;
            if(x0 < x || y0 > y) cout<<"-1\n";
            else {
                ll dx = abs(x - x0);
                cout<<dx + dy<<endl;
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