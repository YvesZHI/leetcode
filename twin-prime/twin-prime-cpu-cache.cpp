#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const uint32_t L1D_CACHE_SIZE = 32768;

uint32_t segmented_sieve(uint32_t limit) {
    uint32_t sqrt = (uint32_t)std::sqrt(limit);
    uint32_t segment_size = std::max(sqrt, L1D_CACHE_SIZE);
    uint32_t count = 0;

    uint32_t i = 3;
    uint32_t n = 3;
    uint32_t s = 3;

    std::vector<bool> sieve(segment_size);
    std::vector<bool> is_prime(sqrt + 1, false);
    std::vector<uint32_t> primes;
    std::vector<uint32_t> multiples;
    uint32_t tmp = 0;

    for (uint32_t low = 0; low <= limit; low += segment_size) {
        std::fill(sieve.begin(), sieve.end(), false);

        uint32_t high = low + segment_size - 1;
        high = std::min(high, limit);

        for (; i * i <= high; i += 2) {
            if (!is_prime[i]) {
                for (uint32_t j = i * i; j <= sqrt; j += i) {
                    is_prime[j] = true;
                }
            }
        }
        for (; s * s <= high; s += 2) {
            if (!is_prime[s]) {
                primes.push_back(s);
                multiples.push_back(s * s - low);
            }
        }

        for (std::size_t i = 0; i < primes.size(); i++) {
            uint32_t j = multiples[i];
            for (uint32_t k = primes[i] * 2; j < segment_size; j += k) {
                sieve[j] = true;
            }
            multiples[i] = j - segment_size;
        }

        for (; n <= high; n += 2) {
            if (!sieve[n - low]) {
                if (tmp == 0) {
                    tmp = n;
                } else {
                    if (n - tmp == 2) {
                        count++;
                    }
                    tmp = n;
                }
            }
        }
    }

    return count;
}

int main(int argc, char **argv) {
    int n;
    while (std::cin >> n) {
        if (n < 5) {
            std::cout << 0 << std::endl;
        } else if (n < 7) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << segmented_sieve(n) << std::endl;
        }
    }

    return 0;
}
