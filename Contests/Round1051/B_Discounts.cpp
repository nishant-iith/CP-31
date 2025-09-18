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
    /***
     * SOlution : Greedy Approach : Try to get the expensive items for free
     * Time Complexity : O(n log n + k log k)
     */
    void solve(){
        // Your code here
        int n, k;
        cin >> n >> k;
        vi a = arrayInput(n);
        vi b = arrayInput(k);

        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());

        ll total_sum = accumulate(a.begin(), a.end(), 0LL);
        ll saving = 0;
        int current = 0;
        for (int x : b) {
            if (current + x <= n) {
                saving += a[current + x - 1];
                current += x;
            } else {
                break;
            }
        }
        cout << total_sum - saving << '\n';
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