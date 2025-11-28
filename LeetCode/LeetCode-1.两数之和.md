---
date: 2025.9.29
tags:
  - C语言
  - LeetCode
  - 数组
---

#原题再现
- 给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** _`target`_  的那 **两个** 整数，并返回它们的数组下标。

- 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

- 你可以按任意顺序返回答案。
[两数之和](https://leetcode.cn/problems/two-sum/description/?envType=problem-list-v2&envId=array)
### 示例：
>**输入：nums = [2,7,11,15], target = 9
>输出：[0,1]
>解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。**

---
# 改版过程
## version 1
```c
	int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
	{ 
		int i,j; 
		for(i=0, j=1; j<numsSize; i++,j=i+1) 
		{ 
		while(target != nums[i] + nums[j]) 
			{
				j++; 
				if(j > 3) 
					break; 
			} 
		} 
	}
```
然而豆包指出了几个**问题**：
1. 循环逻辑错误，没有正确遍历**所有可能的元素对**
2. 硬编码了**数字 3** 作为边界判断，这是不正确的
3. 没有正确设置**返回数组**和返回大小
4. 找到答案后没有正确返回（不知道怎么返回数组qwq）

BTW，当时是懂下面这串代码的意思的，但是不记得怎么使用[[malloc]]了

	/**

	 * Note: The returned array must be malloced, assume caller calls free().

	 */


---

### 总而言之，就迷迷糊糊来到了
## version 2
```c
	int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
	{ 
		int i,j; 
		for(i=0, j=1; j<numsSize; i++,j=i+1) 
		{ 
			while(target != nums[i] + nums[j]) 
			{ 
				j++; 
				if(j > numsSize) 
					break;
			 } 
			while(target == nums[i] + nums[j]) 
			{ 
				int*result = (int*)malloc(2* sizeof(int)); 
				result[1]=i; 
				result[2]=j; 
				*returnSize = 2; 
				return result; 
			} 
		} 
	*returnSize = 0; 
	return NULL; 
	}
```


然而我自以为自己写的很好，但其实问题还很多
1. 搞混了`while`循环与`if`循环的区别
	>`while`循环会一直重复判断条件 ，直到条件不符的时候才会退出
	>`if`循环则是只判断一次

2. 数组是从零开始的，所以我在这个地方犯了两个错
- j>=numsSize就应该退出循环
- `result[1]=i; result[2]=j`应为0和1

```c
	int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
		{ 
		int i , j; 
		for(i=0, j=1; j<numsSize; i++,j=i+1)
		 { 
		 while(target != nums[i] + nums[j]) 
			 { 
			 j++; 
			 if(j >= numsSize) 
			 break; 
			 } 
			if(target == nums[i] + nums[j]) 
			{ 
				int*result = (int*)malloc(2* sizeof(int)); 
				result[0]=i; 
				result[1]=j; 
				*returnSize = 2; 
				return result; } 
			} 
			*returnSize = 0; 
			return NULL; 
		}
```
回来再说我是怎么错的，先去上课了。


再次写这篇文稿已经是几天之后了，这里有一个致命错误
```c
 if(j >= numsSize) 
 break; 
 } 
if(target == nums[i] + nums[j]) 
```
这里直截取最核心的部分。
`break`只是离开了while循环,但仍然会进行if循环的判断，而此时j>numsSize，所以该判断必然无法进行

---
## version 3
```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i,j;
    for(i=0 ; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
            int*result = (int*)malloc(2* sizeof(int));
            result[0]=i;
            result[1]=j;
            *returnSize = 2;
            return result;
            }
        }
        
    }
    *returnSize = 0;
    return NULL;
}
```
用两个for循环才是最基础的二维递增，可读性也大大上升。
但是，有没有更简单的算法呢？