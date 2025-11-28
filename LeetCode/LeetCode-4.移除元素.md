---
date: 2025.10.20
tags:
  - LeetCode
  - C语言
  - 数组
---
## 原题重现
[移除元素](https://leetcode.cn/problems/remove-element/description/?envType=problem-list-v2&envId=array)
给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95)** 移除所有数值等于 `val` 的元素。元素的顺序可能发生改变。然后返回 `nums` 中与 `val` 不同的元素的数量。

假设 `nums` 中不等于 `val` 的元素数量为 `k`，要通过此题，您需要执行以下操作：

- 更改 `nums` 数组，使 `nums` 的前 `k` 个元素包含不等于 `val` 的元素。`nums` 的其余元素和 `nums` 的大小并不重要。
- 返回 `k`。

## 解题思路
**感觉自己越来越快了**
一开始的想法是，找到等于`val`的元素，然后所有数据前移一位
当时真的真的不知道怎么删除元素，更不会用**快慢指针**。
所以
```c
int removeElement(int* nums, int numsSize, int val) { 
	int i=0; 
	int k=1; 
	for(; i<numsSize; i++, k++) { 
		while(nums[i] == val) { 
			for(int j=i; (j+1) <numsSize; j++) {
				nums[j]=nums[j+1]; 
			} 
		} 
	}return k; 
} 
```

好灾难啊qwq

但是之后就有了复杂版的双指针
>定义一个快指针和一个慢指针，当快指针指的数不是val是，慢指针可以跟上快指针；当快指针指的数为val，慢指针不动，快指针前移。如果慢指针跟不上快指针，快指针的数就要赋给慢指针。

```c
int removeElement(int* nums, int numsSize, int val) {
	int k = 0; 
	for (int i = 0; i < numsSize; i++) { 
		if (nums[i] != val) { 
			if (i != k) { // 仅当快、慢指针位置不同时才赋值 
				nums[k] = nums[i]; 
			} k++; 
		} 
	} return k; 
} 
```
但是里面那个if，完全没有必要

```c
int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
```
