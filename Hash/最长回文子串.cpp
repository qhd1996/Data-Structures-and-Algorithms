#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#pragma disable(warning:4996)

using namespace std;

typedef long long LL;
const LL MOD = 1000000007; //MOD为计算hash值时的模数
const LL P = 10000019; //P为计算hash值时的进制数
const LL MAXN = 200010; //MAXN为字符串最长长度

LL powP[MAXN], H1[MAXN], H2[MAXN];

void init() {
	powP[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		powP[i] = (powP[i - 1] * P) % MOD;
	}
}

//calH函数计算str的hash值
void calH(LL H[], string &str) {
	H[0] = str[0];
	for (int i = 1; i < str.length(); i++) {
		H[i] = (H[i - 1] * P + str[i]) % MOD;
	}
}


//calSingleSubH计算H[i...j]
int calSingleSubH(LL H[], int i, int j) {
	if (i == 0) return H[j];
	else return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}
//对称点为i，字符串长len，在[l,r]里二分回文半径
//寻找最后一个满足条件“hashL==hashR”的回文半径
//等价于寻找第一个满足条件“hashL!=hashR”的回文半径，然后减1即可
//isEven当求奇回文时为0，当求偶回文时为1
int binarySearch(int l, int r, int len, int i, int isEven) {
	while (l < r) { //当出现l==r时结束，因为范围是[l,r]
		int mid = (l + r) / 2;
		int H1L = i - mid + isEven, H1R = i;
		int H2L = len - 1 - (mid + i), H2R = len - 1 - (i + isEven);
		int hashL = calSingleSubH(H1, H1L, H1R);
		int hashR = calSingleSubH(H2, H2L, H2R);
		if (hashL != hashR) r = mid; //hash值不相等，说明回文半径<=mid
		else l = mid + 1; //回文值相等，说明回文半径>mid
	}
	return l - 1; //返回最大回文半径
}

int main() {
	init();
	string str;
	getline(cin, str);
	calH(H1, str);
	reverse(str.begin(), str.end());
	calH(H2, str);
	int ans = 0;
	//奇回文
	for (int i = 0; i < str.length(); i++) {
		int maxLen = min(i, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, maxLen, str.length(), i, 0);
		ans = max(ans, k * 2 + 1);
	}
	//偶回文
	for (int i = 0; i < str.length(); i++) {
		int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
		int k = binarySearch(0, m
			
			
			
			
			axLen, str.length(), i, 1);
		ans = max(ans, k * 2);
	}
	printf("%d\n", ans);
	system("pause");
	return 0;
}
