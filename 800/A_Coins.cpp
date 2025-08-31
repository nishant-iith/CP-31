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
 * Problem: In Berland, there are coins of denomination 2 and k.
 * Task: Check if it is possible to form n burles using any number of these coins.
 * Condition: Find non-negative integers x, y such that 2*x + k*y = n.
 * Input: t test cases
 *        For each test case: integers n and k
 * Output: "YES" if possible, otherwise "NO"
 */


class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            ll n , k;
            cin>>n>>k;  // n is greater than equal to k
            if(n%2==0) cout<<"YES\n";
            else {
                if(k%2==0) cout<<"NO\n";
                else cout<<"YES\n";
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