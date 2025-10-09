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

/**
 * Solution : If the maximum and the minimum elements are same, then it is not possible to rearrange the array as it is ugly.
 * Else, we can always rearrange the array in such a way that no two adjacent elements are same.
 * 
 * The only edge case over here is that if it is possible to reaarrange the array such that the array is beautiful the first and 2nd element should not match
 * This can be achieved by putting maximum at first position and minimum at second position. 
 */

class Solution : public Helper {
public:
    void solve(){
        // Your code here
        vi arr = arrayInput();
        if(arr[0] == arr[arr.size()-1]){ 
            cout<<"NO"<<endl; 
            return;
        }
        cout<<"YES"<<endl;
        swap(arr[0], arr[arr.size()-1]);
        swap(arr[1], arr[arr.size()-1]);
        printArray(arr);
        return;
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