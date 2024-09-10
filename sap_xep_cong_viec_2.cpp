#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define MAX 1000001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

struct Schedule{
    int JobID, Deadline, Profit;
};
bool cmp(Schedule a, Schedule b){
    return a.Profit > b.Profit;
}
void TestCase(){
    int n;
    cin >> n;
    vector<Schedule> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].JobID >> v[i].Deadline >> v[i].Profit;
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> mark(max_n + 1, 0);
    int deadline = -1;
    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = v[i].Deadline; j > 0; j--){
            if(!mark[j]){
                mark[j] = 1;
                ans += v[i].Profit;
                cnt++;
                break; 
            }
        }
    }
    cout << cnt << " " << ans << endl;
}
int main(){
    Quick();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */