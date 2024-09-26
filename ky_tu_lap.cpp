#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n;
vector<string> strs;
int minOverlap = INT_MAX;
int countOverlap(string a, string b){
    int frequency[26] = {0};
    int cnt = 0;
    for(char c : a){
        frequency[c - 'A']++;
    }
    for(char c : b){
        frequency[c - 'A']++;
    }
    for(int it : frequency){
        if(it == 2){
            cnt++;
        }
    }
    return cnt;
}
void backTracking(int idx, int currentOverlap){
    if(currentOverlap >= minOverlap) return;
    if(idx == n){
        minOverlap = currentOverlap;
        return;
    }
    else{
        for(int i = idx; i < n; i++){
            swap(strs[i], strs[idx]);
            int newOverlap = currentOverlap;
            if(idx > 0){
                newOverlap += countOverlap(strs[idx - 1], strs[idx]);
            }
            backTracking(idx + 1, newOverlap);
            swap(strs[i], strs[idx]);
        }
    }
    
}
void TestCase(){
    cin >> n;
    strs.clear();
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        strs.push_back(s);
    }
    minOverlap = INT_MAX;
    backTracking(0, 0);
    cout << minOverlap << endl;
}
int main(){
    Quick();
    int t = 1;
    while(t--){
        TestCase();
    }
    return 0;
}
/* No Code - No Bug */