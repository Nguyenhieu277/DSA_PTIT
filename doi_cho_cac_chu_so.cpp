#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
#define max_n 1001
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

/*created by: HiuDev*/

string maxNumber;
void backTracking(string str, int k){
	if(k == 0){
		return;
	}
	else{
		for(int i = 0; i < str.size(); i++){
			for(int j = i + 1; j < str.size(); j++){
				if(str[i] < str[j]){
					swap(str[i], str[j]);
					if(str > maxNumber){
						maxNumber = str;
					}
					backTracking(str, k - 1);
					swap(str[i], str[j]);
				}
			}
		}
	}
}
void TestCase(){
	int k;
	string str;
	cin >> k >> str;
	maxNumber = str;
	backTracking(str, k);
	cout << maxNumber << endl;
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