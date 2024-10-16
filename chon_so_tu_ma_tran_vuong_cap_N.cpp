#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

int n, k;
vector<vector<int>> matrix(max_n, vector<int>(max_n));
int visited[max_n];
int cnt = 0;
vector<int> current;
vector<vector<int>> result;
void backTracking(int row, int sum){
    if(row == n){
        if(sum == k){
            cnt++;
            result.push_back(current);
        }
        return;
    }
    else if(row < n){
        for(int col = 0; col < n; col++){
            if(!visited[col]){
                visited[col] = 1;
                current.push_back(col);
                backTracking(row + 1, sum + matrix[row][col]);
                current.pop_back();
                visited[col] = 0;
            }
        }
    }
}
void TestCase(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cnt = 0;
    current.clear();
    memset(visited, 0, sizeof(visited));
    backTracking(0, 0);
    cout << cnt << endl;
    for(auto it : result){
        for(int i = 0; i < it.size(); i++){
            cout << it[i] + 1 << " ";
        }
        cout << endl;
    }
}
int main(){
    Quick();
    TestCase();
    return 0;
}
/* No Code - No Bug */