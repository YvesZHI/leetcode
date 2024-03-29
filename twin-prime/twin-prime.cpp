#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int Prime(int n) {
  vector<bool> isPrime(n + 1, true);
  uint16_t *primes = new uint16_t[n / (int)(log10(n) + 0.5)](); // 100000000
  int counter = 1;
  int primeCnt = 0;
  bool sw = false;
  int tmp;
  isPrime[0] = isPrime[1] = isPrime[4] = false;
  primes[primeCnt++] = 2;
  primes[primeCnt++] = 3;

  for (int i = 5; i < n + 1;) {
    if (isPrime[i]) {
      primes[primeCnt++] = i;
      if (sw && isPrime[i - 2]) {
        counter++;
      }
    }
    for (int j = 0; j < primeCnt; ++j) {
      tmp = primes[j] * i;
      if (tmp >= n + 1) {
        break;
      }
      if (tmp % 6 == 5 || tmp % 6 == 1) {
        isPrime[tmp] = false;
        if (!(i % primes[j])) {
          break;
        }
      }
    }

    if (!sw) {
      i += 2;
      sw = true;
    } else {
      i += 4;
      sw = false;
    }
  }
  delete[] primes;
  return counter;
}

int main() {
  int n;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> n) {
    auto start = std::chrono::system_clock::now();
    if (n < 5) {
      cout << 0 << endl;
    } else if (n < 7) {
      cout << 1 << endl;
    } else {
      cout << Prime(n) << endl;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << diff.count() << endl;
  }

  return 0;
}
