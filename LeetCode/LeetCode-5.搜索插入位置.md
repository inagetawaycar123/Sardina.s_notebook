---
date: 2025-10-21
tags:
  - LeetCode
  - 数组
  - 双指针
---

## 原题重现
[搜索插入位置](https://leetcode.cn/problems/search-insert-position/submissions/672193571/?envType=problem-list-v2&envId=array)
>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
>请必须使用时间复杂度为 `O(log n)` 的算法。

## 妈呀给我一把子秒了居然哈哈
```c
int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;
    for(; i < numsSize; i++){
        if(nums[i] >= target){
            return i;
        }
    }return 0;
}
```

第一次写的长这样，但是在一个测试用例里面栽跟头了
`nums = [1,3,5,6]`
`target = 7`

结果你猜怎么着
一下子反应过来了

```c
int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;
    for(; i < numsSize; i++){
        if(nums[i] >= target){
            return i;
        }
    }return numsSize;
}
```

**秒的很突然**
我就说嘛，原来我做错了
我的时间复杂度是O(n)，题目要求O(logn)

再来
```c
int searchInsert(int* nums, int numsSize, int target) {
    int mid;
    int lt = 0, rt = numsSize-1, ans = numsSize;
    while(lt <= rt){
        mid = (rt-lt)/2 + lt;
        if(nums[mid]<target){
            lt = mid + 1;
        }else if(nums[mid]>target){
            rt = mid - 1;
        }else{
            return mid;
        }
    }return lt;
}
```

有必要这么好做吗，本可就试了没一会