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
    void solve(){
        long long n; int m;
        cin >> n >> m;
        vector<long long> a(m);
        for (int i = 0; i < m; ++i) cin >> a[i];

        bool flag = false;
        rloop(i, m, 1){
            if(a[i] == 1){
                flag = true;
                break;
            }
        }

        // we 1 is there in between the array it means it is a subarray with two different sections
        if(!flag) cout<<n-a[m-1] + 1<<endl;
        else cout<<"1\n";

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