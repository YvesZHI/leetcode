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
