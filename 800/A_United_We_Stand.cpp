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

class Solution : public Helper {
    public:
        /**
         * If I have more than 1 distinct element then the answer exists always
         * If we want x%y != 0 then we can simply take y > x
         * So simple we will take the max element from the given array and put it in the arr2 rest all elements in the array 1
         */
        void solve(){
            // Your code here
            vi arr = arrayInput();
            vi arr1, arr2;
            int mx = *max_element(all(arr));

            loop(i, 0, arr.size()){
                if(arr[i] == mx) arr2.pb(arr[i]);
                else arr1.pb(arr[i]);
            }

            if(arr1.size() == 0) cout<<"-1\n";
            else {
                cout<<arr1.size()<<" "<<arr2.size()<<endl;
                for(auto x : arr1) cout<<x<<" ";
                cout<<endl;
                for(auto x : arr2) cout<<x<<" ";
                cout<<endl;
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