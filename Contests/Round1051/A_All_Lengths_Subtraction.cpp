#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

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
public:
    /**
     * Solution : Using two pointers approach
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    void solve(){
        // Your code here
        vi a = arrayInput();
        int l = 0 , r = a.size()-1;

        int cur = 1;
        while(l < r){
            if(a[l] != cur && a[r] != cur){
                cout<<"NO\n";
                return;
            }
            else if(a[l] == cur) l++;
            else r--;
            cur++;
        }
        cout<<"YES\n";
    }

    // Alternative solve function for the problem
    // For yes the array should be combination of increasing and decreasing (reverse increasing) sequence
    void solve_alter_1(){
        vi a = arrayInput();
        if (a.size() == 0) {
            cout << "YES\n";
            return;
        }

        int l = 0, r = a.size()-1;
        while (l + 1 < a.size() && a[l] < a[l + 1]) l++;
        while (r > 0 && a[r] < a[r - 1]) r--;
        if (l == r) {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }

    // Alternative solve function for the problem
    void solve_alter_2(){
        vi a = arrayInput();
        long long s = a[0];
        loop(i, 1, a.size()){
            if(a[i]>a[i-1]){
                s += a[i]-a[i-1];
            }
        }
        
        if(s==a.size()) cout<<"YES\n";
        else cout<<"NO\n";
    }
};

int main(){
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