---
date: 2025-11-24
tags:
  - LeetCode
  - C语言
  - 枚举
---
## 原题
[计算质数](https://leetcode.cn/problems/count-primes/description/?envType=problem-list-v2&envId=enumeration)

>给定整数 `n` ，返回 _所有小于非负整数 `n` 的质数的数量_ 。

## 思路
1. 暴力枚举
```c
int countPrimes(int n) {
    int count = 0;
    for(int i = 2; i < n; i++){
        for(int j = 2; j <= sqrt(i); j++){
            if(i%j == 0){
                count--;
                break;
            }
        }
        count++;
    }
    return count;
}
```

2. 埃式筛
```c
int countPrimes(int n) {
    if(n < 2){
        return 0;
    }
    int is_Prime[n];
    int ans = 0;
    memset(is_Prime, 0, sizeof(is_Prime));
    for(int i = 2; i < n; i++){
        if(!is_Prime[i]){
            ans++;
            if((long long)i*i < n){
                for(int j = i*i; j < n; j += i){
                    is_Prime[j] = 1;
                }
            }
        }
        
        
    }
    return ans;
}
```

3. 线性筛（为什么性能比埃式筛差啊）