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
 * Problem: Given a binary string s of length n.
 * Operation: Choose indices i < j < k and cyclically shift (si, sj, sk)
 *            either left or right.
 * Task: Find the minimum number of operations needed to sort s
 *       (all 0s before all 1s).
 *
 * Input: t test cases
 *        For each test case:
 *          - integer n (length of string)
 *          - binary string s
 * Output: Minimum operations to sort the string
 */


class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            int n;
            cin >> n;
            string s;
            cin >> s;

            int z = 0;
            for(char c : s){
                if(c == '0') z++;
            }

            int ans = 0;
            for(int i=0; i<z; i++){
                if(s[i] == '1') ans++;
            }
            
            cout << ans << endl;
        }
};

/**
 * Solution Explanation:
 * 
 * Key Insight: We want to sort the binary string so all 0s come before all 1s.
 * The final sorted string will have all 0s in the first 'z' positions (where z = count of 0s)
 * and all 1s in the remaining positions.
 * 
 * Approach:
 * 1. Count the total number of 0s in the string (z)
 * 2. In the first 'z' positions, count how many 1s are present
 * 3. Each 1 in the first 'z' positions needs to be moved to the right part
 * 4. Using the allowed operation (cyclic shift of 3 elements), we can move any 1 
 *    from the first 'z' positions to the last 'n-z' positions in exactly 1 operation
 * 5. Hence, the answer is the count of 1s in the first 'z' positions
 * 
 * Why this works:
 * - We can always move a 1 from position i (where i < z) to a position k (where k >= z)
 *   using a suitable j (where i < j < k) in one operation
 * - The minimum number of operations equals the number of misplaced 1s in the left part
 */

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