#include <iostream>
using namespace std;
int n, arr[1010];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		// 맨 뒤에서부터 i개의 원소는 순서가 정해졌고, 바뀔 일이 없으므로 j < n - (i + 1)까지만 비교한다.
		// j번째 원소가 j+1번째 원소보다 큰 경우 두개의 위치를 swap한다.
		for (int j = 0; j < n - (i + 1); j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
