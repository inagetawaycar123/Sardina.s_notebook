---
date: 2025.10.21
tags:
  - C语言
  - LeetCode
  - 二分法查找
---
## 原题
给你一个非负整数 `x` ，计算并返回 `x` 的 **算术平方根** 。

由于返回类型是整数，结果只保留 **整数部分** ，小数部分将被 **舍去 。**

[x的平方根](https://leetcode.cn/leetbook/read/binary-search/xe9cog/)

## 解法

```c
int mySqrt(int x) {
    long lt = 0;
        long rt = x;
        while(lt < rt){
            long m=((rt-lt)/2+lt);
            if(m*m > x){
                rt = m-1;
            }
            else if(m*m < x){
                lt = m+1;
            }else{
                return m;
            }
        }
        if(lt*lt <= x){
            return lt;
        }return --lt;
}
```
就，多调试几次