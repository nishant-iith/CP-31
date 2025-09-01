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
 * Problem: Given array a of non-negative integers.
 * Operation: Choose integer x, define bi = ai ⊕ x (XOR).
 * Task: Find x such that b1 ⊕ b2 ⊕ ... ⊕ bn = 0.
 *
 * Constraint: If a solution exists, 0 ≤ x < 2^8.
 *
 * Input: t test cases
 *        For each test case:
 *          - integer n (size of array)
 *          - array a of n integers (0 ≤ ai < 2^8)
 * Output: Valid x (0 ≤ x < 2^8), or -1 if not possible
 * 
 * 
 * 😠
 * Intution : If the size of the array is even then x will be even times and eventually x xor will be 0 so x will never appear in b1 ⊕ b2 ⊕ ... ⊕ bn. 
 * Case 1 : if size is even then check a1 ⊕ a2 ⊕ ... ⊕ an  is non zero then return -1 otherwise x can be anything.
 * Case 2 : if size is odds then  b1 ⊕ b2 ⊕ ... ⊕ bn = a1 ⊕ a2 ⊕ ... ⊕ an ⊕ x and we need this to be equal to 0. So we can keep x = a1 ⊕ a2 ⊕ ... ⊕ an.
 */


class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vi arr = arrayInput();
            ll xr = 0;
            loop(i, 0, arr.size()){
                xr ^= arr[i];
            }
            if(arr.size() % 2 == 0 && xr != 0) cout<<-1<<endl;
            else if(arr.size() % 2 == 1) cout<<xr<<endl;
            else cout<<arr[arr.size()-1]<<endl;
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