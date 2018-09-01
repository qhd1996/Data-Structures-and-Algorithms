//用有限队列实现huffman tree
#include<cstdio>
#include<queue>
using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);
	while (n != 0) {
		priority_queue<int, vector<int>, greater<int> > minPQ;
		int x;
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &x);
			minPQ.push(x);
		}
		int sum = 0;
		while (minPQ.size()>1) {
			//取出最小的两个元素  
			int a = minPQ.top();
			minPQ.pop();
			int b = minPQ.top();
			minPQ.pop();
			//求和  
			sum += (a + b);
			//把新得到的父节点的重量放入堆中  
			minPQ.push(a + b);
		}
		printf("%d", sum);
		scanf_s("%d", &n);
	}
	return 0;
}
