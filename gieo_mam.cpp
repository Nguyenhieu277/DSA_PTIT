#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/
bool checkValid(vector<vector<int>>& grid, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}
void SowSeeds(vector<vector<int>>& grid, int rows, int cols){
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        int check = 0;
        for(int i = 0; i < size; i++){
            auto top = q.front();
            q.pop();
            int row = top.first, col = top.second;
            for(int i = 0; i < 4; i++){
                int rowi = row + dx[i];
                int coli = col + dy[i];
                if(rowi >= 0 && rowi < rows && coli >= 0 && coli < cols && grid[rowi][coli] == 1){
                    q.push({rowi, coli});
                    check = 1;
                    grid[rowi][coli] = 2;
                }
            }
        }
        if(check) cnt++;
    }
    if(checkValid(grid, rows, cols)) cout << cnt << endl;
    else cout << -1 << endl;
}
void TestCase(){
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int> (cols));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> grid[i][j];
        }
    }
    SowSeeds(grid, rows, cols);
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