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
        void solve(){
            // Your code here
            vi arr = arrayInput();

            vi arr2;
            arr2.pb(arr[0]);
            loop(i, 1, arr.size()){
                if(arr[i] >= arr[i-1]){
                    arr2.pb(arr[i]);
                }
                else {
                    arr2.pb(arr[i]);
                    arr2.pb(arr[i]);
                }
            }

            cout<<arr2.size()<<endl;

            loop(i, 0, arr2.size()){
                cout<<arr2[i]<<" ";
            }
            cout<<endl;
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