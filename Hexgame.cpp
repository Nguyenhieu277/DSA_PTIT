#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

const vector<int> target = {1, 2, 3, 8, 0, 0, 4, 7, 6, 5};

vector<int> spinLeft(const vector<int>& nums) {
    vector<int> result = nums;
    result[0] = nums[3];
    result[1] = nums[0];
    result[3] = nums[7];
    result[5] = nums[1];
    result[7] = nums[8];
    result[8] = nums[5];
    return result;
}

vector<int> spinRight(const vector<int>& nums) {
    vector<int> result = nums;
    result[1] = nums[4];
    result[2] = nums[1];
    result[4] = nums[8];
    result[6] = nums[2];
    result[8] = nums[9];
    result[9] = nums[6];
    return result;
}

string toString(const vector<int>& nums) {
    string s;
    for (int n : nums) s += to_string(n) + ",";
    return s;
}

int BFS(const vector<int>& start) {
    unordered_set<string> visited;
    queue<pair<vector<int>, int>> q;
    q.push({start, 0});
    visited.insert(toString(start));

    while (!q.empty()) {
        auto [current, step] = q.front();
        q.pop();
        
        if (current == target) return step;

        vector<int> leftSpin = spinLeft(current);
        vector<int> rightSpin = spinRight(current);

        string leftStr = toString(leftSpin);
        string rightStr = toString(rightSpin);

        if (visited.find(leftStr) == visited.end()) {
            q.push({leftSpin, step + 1});
            visited.insert(leftStr);
        }

        if (visited.find(rightStr) == visited.end()) {
            q.push({rightSpin, step + 1});
            visited.insert(rightStr);
        }
    }

    return -1; // Trường hợp không tìm thấy kết quả
}

void TestCase() {
    vector<int> nums(10);
    cin >> nums[0] >> nums[1] >> nums[2];
    cin >> nums[3] >> nums[4] >> nums[5] >> nums[6];
    cin >> nums[7] >> nums[8] >> nums[9];
    cout << BFS(nums) << endl;
}

int main() {
    Quick();
    int t;
    cin >> t;
    while (t--) {
        TestCase();
    }
    return 0;
}
