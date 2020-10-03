#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_V 1000
using namespace std;

//1���� �� ������ �ּ� ������ش�.
unsigned char sieve[(MAX_V + 8) / 8];

bool isPrime(int k) {
	//(k & 7) == k % 7 �� �Ȱ���
	// 1 << (k & 7)�� 1�� �ش��Ʈ�� �̵������ش�.
	return sieve[k >> 3] & (1 << (k & 7));
}

void setComposite(int k) {
	//�ش��ϴ� ��Ʈ�� 0���� �����.
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
//	//0�� 1�� ���ܽ�Ų��.
//	setComposite(0);
//	setComposite(1);
//	//������ ���� ��Ī�� �̷�⶧���� �����ٱ����� ����.
//	int sqrtn = (int)(sqrt(N));
//	for (int i = 2; i <= sqrtn; i++) {
//		if (isPrime(i)) {
//			//i * 0 ���� i * (i - 1)���� �� ���ںκ��� �̹� ����
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