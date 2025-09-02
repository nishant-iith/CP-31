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

class Solution : public Helper {
    private:
        bool isOps(string &s, int i, int j){
            if(s[i] == '0' && s[j] == '1') return true;
            if(s[i] == '1' && s[j] == '0') return true;
            return false;
        }
    public:
        void solve(){
            // Your code here
            int n = 0;
            cin>>n;
            int ans = n;
            string s = stringInput();

            int i = 0; 
            int j = n - 1;
            while(i < j){
                if(isOps(s, i, j)){
                    ans -= 2;
                    i++;
                    j--;
                }
                else break;
            }

            cout<<ans<<endl;
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