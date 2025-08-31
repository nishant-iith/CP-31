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
 * Question: Given an array of 1s and -1s. We are allowed to perform the following operations
 * 1. We can change any -1 to 1.
 * 2. We can change any 1 to -1.
 *
 * Now we need to find the minimum number of operations required to make the array sum >=0 and product as 1.
 * 
 * 
 * Solution : We will keep a positive count and a negative count 
 */

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            vi arr = arrayInput();
            ll n = arr.size();
            
            ll pos = 0, neg = 0, ops = 0;
            loop(i, 0 ,n){
                if(arr[i] == 1) pos++;
                else neg++;
            }
            while(pos < neg || neg % 2 == 1){
                ops++;
                neg--;
                pos++;
            }
            cout<<ops<<"\n";
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