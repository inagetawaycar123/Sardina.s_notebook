---
date: 2025.10.27
tags:
  - LeetCode
  - C语言
  - 二分法查找
---
## 原题
[搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=binary-search)

整数数组 `nums` 按升序排列，数组中的值 **互不相同** 。

在传递给函数之前，`nums` 在预先未知的某个下标 `k`（`0 <= k < nums.length`）上进行了 **向左旋转**，使数组变为 `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]`（下标 **从 0 开始** 计数）。例如， `[0,1,2,4,5,6,7]` 下标 `3` 上向左旋转后可能变为 `[4,5,6,7,0,1,2]` 。

给你 **旋转后** 的数组 `nums` 和一个整数 `target` ，如果 `nums` 中存在这个目标值 `target` ，则返回它的下标，否则返回 `-1` 。

你必须设计一个时间复杂度为 `O(log n)` 的算法解决此问题。

## 未能秒掉，实属可惜
不过从豆包哪里汲取了一些思路，发现可以从比较lt和mid入手
找到顺序排列的那半边
然后看target是不是按顺序排的，不然肯定就在无序的那边

```c
int search(int* nums, int numsSize, int target) {
    int lt = 0;
    int rt = numsSize-1;
    while(lt <= rt){
        int mid = (rt-lt)/2 + lt;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[lt] <= nums[mid]){
            if(nums[lt]<=target && target<=nums[mid]){
                rt = mid - 1;
            }else{
                lt = mid + 1;
            }
        }else{
            if(nums[mid]<=target && target<=nums[rt]){
                lt = mid + 1;
            }else{
                rt = mid - 1;
            }
        }
    }return -1;
}
```

其他部分就非常套路化了

不过这可是第一个中等难度题耶

BTW，不做算法题浑身难受