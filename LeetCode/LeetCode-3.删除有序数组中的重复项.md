---
date: 2025.10.6
tags:
  - LeetCode
  - C语言
  - 数组
---
# 原题重现 
[删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/solutions/2807162/gen-zhao-wo-guo-yi-bian-shi-li-2ni-jiu-m-rvyk)
给你一个 **非严格递增排列** 的数组 `nums` ，请你 **[原地](http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95)** 删除重复出现的元素，使每个元素 **只出现一次** ，返回删除后数组的新长度。元素的 **相对顺序** 应该保持 **一致** 。然后返回 `nums` 中唯一元素的个数。

考虑 `nums` 的唯一元素的数量为 `k` ，你需要做以下事情确保你的题解可以被通过：

- 更改数组 `nums` ，使 `nums` 的前 `k` 个元素包含唯一元素，并按照它们最初在 `nums` 中出现的顺序排列。`nums` 的其余元素与 `nums` 的大小不重要。
- 返回 `k` 。

**判题标准:**

系统会用下面的代码来测试你的题解:

```c
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

如果所有断言都通过，那么您的题解将被 **通过**。

## 解题思路
这一题我花的时间很短，但我的答案还是在时间上太长
**思路**大概是：
1. 检查出这个元素与下一个元素相同的位置
2. 将这个元素后面的所有元素向前移一位
3. 继续从这个元素判断

## my version

```c
int removeDuplicates(int* nums, int numsSize) {
    int length = numsSize;
    for(int i=0; i<numsSize-1; i++){
        while(nums[i]==nums[i+1]&&i<length-1){
            for(int j=i; j<length-1; j++){
                nums[j]=nums[j+1];
            }length--;
        }
    }int k = length;
    return k;
}
```
我曾犯了几个错：
- 把内层循环的条件写成nums\[j+1]，因为我觉得这样可以直接判断nums有没有结束。***BUT***，你知道为啥不行吗。只有char型数组，才会最后一个储存\0，int型最后一个是正常元素，无法判断结没结束

## 进化版My Version
```c
int removeDuplicates(int* nums, int numsSize) {
    int i, j;
    for(i=0, j=0; j<numsSize; j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }return ++i;
}
```
是我做它的变式题的时候发现的[[LeetCode-4.移除元素]]


