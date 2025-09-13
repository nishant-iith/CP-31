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
 * Problem: Define f(a) = cost + (a1 - a2 + a3 - a4 + ... ± an).
 *          Initially cost = 0.
 *
 * Game rules:
 *   - Alice and Bob play alternately (Alice starts).
 *   - On each turn, a player must:
 *       1) End the game, OR
 *       2) Choose l,r (1 ≤ l ≤ r ≤ n) and swap a[l], a[r],
 *          which adds (r-l) to cost.
 *   - Alice maximizes f(a), Bob minimizes f(a).
 *
 * Task: Find final value of f(a) if both play optimally.
 *
 * Input: t test cases
 *        For each test case:
 *          - integer n (array length)
 *          - array a of n integers
 * Output: Final value of f(a) for each test case
 */


class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            int n;
            cin >> n;
            vector<ll> a(n);
            for(int i = 0; i < n; ++i) {
                cin >> a[i];
            }
            
            // This is a classic game theory problem with optimal play
            // The solution depends on whether n is odd or even
            
            vector<ll> sorted_a = a;
            sort(all(sorted_a));
            
            if (n % 2 == 1) {
                // For odd length arrays, the optimal result is the alternating sum
                // of the sorted array
                ll result = 0;
                for(int i = 0; i < n; ++i) {
                    if(i % 2 == 0) {
                        result += sorted_a[i];
                    } else {
                        result -= sorted_a[i];
                    }
                }
                cout << result << endl;
            } else {
                // For even length arrays, the result is (max - min) / 2
                // This comes from the game theory analysis where players can
                // optimally manipulate the array to get this value
                ll result = (sorted_a[n-1] - sorted_a[0]) / 2;
                cout << result << endl;
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