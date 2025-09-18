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
     * Solution : Perform Topological Sort (Kahn's Algorithm)
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    void solve(){
        // Your code here
        int n;
        cin >> n;
        vector<vi> adj(n + 1);
        vi in_degree(n + 1, 0);
        loop(i, 0, n - 1) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x > y) {
                adj[v].pb(u);
                in_degree[u]++;
            } else {
                adj[u].pb(v);
                in_degree[v]++;
            }
        }
        queue<int> q;
        loop(i, 1, n + 1) if (in_degree[i] == 0) q.push(i);

        vi perm(n + 1);
        int order = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            perm[u] = order++;
            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << perm[i] << " ";
        }
        cout << '\n';
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