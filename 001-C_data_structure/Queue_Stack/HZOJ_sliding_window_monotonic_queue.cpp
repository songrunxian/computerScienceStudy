#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define MAX_N 300000
int a[MAX_N + 5];	//store queue elements
int q[MAX_N + 5], head = 0, tail = 0;	//store queue index

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <=n ; i++) cin >> a[i];
	for (int i = 1; i <=k ; i++) {
		while(tail - head && a[q[tail - 1]] >= a[i]) tail--; // tail - head is or 0 prove the queue's lengh 
		q[tail++] = i;	
		// the tail should stay at a position after the last element in the queue
	}
	for (int i = k; i <= n; i++) {
		while(tail -head && a[q[tail -1]] >= a[i]) tail--;
		if (q[head] <= i - k) head++;
		q[tail++] = i;
		i == k || cout << " ";
		cout << a[q[head]];
	}
	cout << endl;
	head = tail = 0;
	for(int i = k; i <= n; i++) {
		while(tail - head && a[q[tail-1]] <= a[i]) tail--;
		q[tail++] = i;
		if(q[head] <= i-k) head++;
		i == k || cout << " ";
		cout << a[q[head]];
	}
	cout << endl;
}

