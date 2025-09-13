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
 * Problem: Given integer x (1 ≤ x < 10^8).
 * Task: Find integer y (1 ≤ y < 10^9) such that
 *       concatenation x#y is divisible by (x + y).
 * Note: It can be proven that such y always exists.
 *
 * Input: t test cases
 *        Each test case: single integer x
 * Output: For each test case, print any valid y
 */


class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            int x;
            cin >> x;
            cout << 2 * x << endl;
        }
};

/**
 * Solution Explanation:
 * 
 * Key Insight: We need to find a y such that x#y is divisible by (x + y).
 * 
 * Mathematical Derivation:
 * 1. Let's express the problem mathematically:
 *    - We want (x#y) % (x + y) = 0
 *    - x#y = x * 10^d + y, where d is the number of digits in y
 *    - So we need (x * 10^d + y) % (x + y) = 0
 * 
 * 2. To simplify this, we look for a relationship between y and x.
 *    Let's try y = k*x for some constant k (this makes y a multiple of x)
 * 
 * 3. With y = k*x:
 *    - x#y = x * 10^d + k*x = x * (10^d + k)
 *    - (x + y) = x + k*x = x * (1 + k)
 *    - We need (x * (10^d + k)) % (x * (1 + k)) = 0
 * 
 * 4. Since x is a common factor, this simplifies to:
 *    (10^d + k) % (1 + k) = 0
 * 
 * 5. Now we need to find a value of k that makes this work for any d.
 *    A key insight is to use modular arithmetic:
 *    - We know 10 ≡ 1 (mod 3), so 10^d ≡ 1 (mod 3) for any d ≥ 1
 *    - If we choose k = 2, then:
 *      - (10^d + k) = (10^d + 2) ≡ (1 + 2) ≡ 0 (mod 3)
 *      - (1 + k) = (1 + 2) = 3
 *      - So (10^d + 2) % 3 = 0, which means (10^d + 2) is divisible by 3
 * 
 * 6. Therefore, choosing k = 2 (i.e., y = 2*x) works:
 *    - x#y = x * (10^d + 2)
 *    - (x + y) = 3*x
 *    - Since (10^d + 2) % 3 = 0, we have (10^d + 2) = 3*m for some integer m
 *    - So x#y = x * 3*m = 3*x*m
 *    - And (x + y) = 3*x
 *    - Therefore (x#y) % (x + y) = (3*x*m) % (3*x) = 0
 * 
 * Verification with example:
 *  - If x = 12, we choose y = 24 (2*x)
 *  - d = 2 (since y=24 has 2 digits)
 *  - x#y = 1224
 *  - (x + y) = 36
 *  - Check divisibility: 1224 % 36 = 0, so it works
 * 
 * Why this works for all cases:
 *  - The modular arithmetic property 10^d ≡ 1 (mod 3) holds for all d≥1
 *  - Therefore (10^d + 2) % 3 = 0 always holds
 *  - This guarantees that x#(2*x) is divisible by 3*x = (x + 2*x)
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