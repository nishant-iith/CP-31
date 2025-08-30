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
};

/**
 * Question : Ntarsis has an array a of length n. He is allowed to perform one type of operation on it (zero or more times):
 * Choose an index i (1≤i≤n−1).
 * Add 1 to a1,a2,…,ai.
 * Subtract 1 from ai+1,ai+2,…,an.
 * The values of a can be negative after an operation.
 * Determine the minimum operations needed to make a not sorted.
 *
 * Solution : If the array is already not sorted, no operations are needed.
 * If the array is sorted, we need to find the minimum number of operations
 * to make it not sorted. This can be done by finding the minimum difference
 * between adjacent elements and performing operations accordingly.
 */

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vi arr = arrayInput();
            vi arr2 = arr;
            int ops = INT_MAX;
            sort(all(arr2));
            if(arr2 != arr) cout<<"0\n";
            else {
                loop(i, 1, arr.size()){
                    ops = min(ops, arr[i] - arr[i-1]);
                }
                cout<<(ops/2) + 1<<"\n";  // /2 will make both values equal and + 1 will give the required operations
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