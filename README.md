# leetcode


### Two Sum ###
Description: https://leetcode.com/problems/two-sum/

Solution:
```
int[] twoSum(int[] nums, int target)
    hashmap hm    // key: element of nums; value: index of element of nums
    for each n in nums
        if found(target - n) in hm
            return [hm[target - n], nums.indexOf(n)]
        else
            hm[n] = nums.indexOf(n)
        fi
    end
    return []
end
```

### Prime ###

Algorithm:<br>
Euler's sieve: https://www.jianshu.com/p/2031036dba4b<br>
Prime 6k rule: https://primes.utm.edu/notes/faq/six.html<br>
CPU cache: https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes<br>
Number of primes: https://en.wikipedia.org/wiki/Prime_number#Number_of_primes_below_a_given_bound<br>
PI(n): https://www.dcode.fr/prime-number-pi-count<br>
List of primes: http://compoasso.free.fr/primelistweb/page/prime/liste_online_en.php
