#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_V 1000
using namespace std;

//1개를 더 여유를 둬서 만들어준다.
unsigned char sieve[(MAX_V + 8) / 8];

bool isPrime(int k) {
	//(k & 7) == k % 7 과 똑같음
	// 1 << (k & 7)은 1을 해당비트로 이동시켜준다.
	return sieve[k >> 3] & (1 << (k & 7));
}

void setComposite(int k) {
	//해당하는 비트를 0으로 만든다.
	sieve[k >> 3] &= ~(1 << (k & 7));
}

int eratosthenes(int N, int K) {
	int cnt = 0;
	memset(sieve, 255, sizeof(sieve));
	setComposite(0);
	setComposite(1);
	for (int i = 2; i <= N; i++) {
		if (isPrime(i)) {
			if (++cnt == K) return i;
			for (int j = i * i; j <= N; j += i) {
				if (isPrime(j)) {
					if (++cnt == K) return j;
					setComposite(j);
				}
			}
		}
	}
	return cnt;
}

//void eratosthenes(int N, int K) {
//	memset(sieve, 255, sizeof(sieve));
//	//0과 1은 제외시킨다.
//	setComposite(0);
//	setComposite(1);
//	//숫자의 곱은 대칭을 이루기때문에 제곱근까지만 돈다.
//	int sqrtn = (int)(sqrt(N));
//	for (int i = 2; i <= sqrtn; i++) {
//		if (isPrime(i)) {
//			//i * 0 부터 i * (i - 1)까지 뒤 숫자부분이 이미 계산됌
//			for (int j = i * i; j <= N; j += i) {
//				setComposite(j);
//			}
//		}
//	}
//}

int main(void) {
	int N, K;
	cin >> N >> K;
	int result = eratosthenes(N, K);
	//for (int i = 0; i < (N >> 3)+1; i++) {
	//	for (int j = 0; j < 8; j++) {
	//		cout << ((sieve[i]>>j) & 1) << " ";
	//	}
	//	cout << endl;
	//}
	cout << result << endl;
}