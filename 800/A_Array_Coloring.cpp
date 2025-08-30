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
 * Question : Given an array of integers, determine wheather it is possible to color all its elements in two colors in such a way that sum of the elements of both colors have the same parity. (Meaning of same parity is that both sums are either even or odd)
 *
 * Solution: If the count of odd numbers is even, then it's possible to partition the array into two subsets with the same parity. Otherwise, it's not.
 */

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vi arr = arrayInput();
            int oddCtr = 0;
            loop(i, 0, arr.size()){
                if(arr[i] % 2 == 1) oddCtr++;
            }
            if(oddCtr % 2 == 0) cout<<"YES\n";
            else cout<<"NO\n";
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