---
date: 2025.10.4
tags:
  - C语言
  - LeetCode
  - 数组
---
# 原题再现

>编写一个函数来查找字符串数组中的最长公共前缀。
>如果不存在公共前缀，返回空字符串 `""`。

[最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/description/?envType=problem-list-v2&envId=array)

本题会输入一个**字符串数组**`char** strs`，主包经过对豆包的多次拷问，终于知道了`** strs`是个什么鬼。
>假如这里有一个字符串数组`char* arr[] = {"hello", "world", NULL}`
>我令`char** strs = arr`
>那么此时\*\*strs = 'h'，而\*strs则是指向"hello"的第一个元素的指针

**由此我有了一个大致思路：**
1. 判断所有字符串的第一个字符是否一致，如果一致，**把该字符写入result的第一个元素**
2. 判断第二个字符。。。
---
## version 1
```c
char* longestCommonPrefix(char** strs, int strsSize) {
    char* result = (char*)malloc(10*sizeof(char));
    int i = 0;
    if (strsSize == 0) return strdup("");
    for(int j=0; j<strlen(strs[i])-1; j++){
        for(i=0; i<strsSize-1; i++){
            if(strs[i][j]!=strs[i+1][j])
                break;
            if(strs[i][j]==strs[i+1][j]&&((i+1) == strsSize-1)){
                result[j]=strs[i][j];
                result[j+1]='/0';
            }
        }
    }
    return result; 
}
```
这一版出现的主要问题太多了
- `malloc`分配内存的问题：你怎么知道是10个char呢
- 终止符不是/0而是\0
---
## version 2
```c
char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    char* result;
    if (strsSize == 0) return strdup("");
    if(strsSize != 0){
        for(int j=0; j < strlen(strs[i])-1; j++){
            for(i=0; i<strsSize-1; i++){
                if(strs[i][j]!=strs[i+1][j]&&j==0)
                    return strdup("");
                if(strs[i][j]!=strs[i+1][j])
                    break;
                if(strs[i][j]==strs[i+1][j]&&((i+1) == strsSize-1)){
                    result = (char*)malloc(j+2);
                    result[j]=strs[i][j];
                    result[j+1]='\0';
                }
            }
        }
        return result;
    }
    return 0;
}
```
这一版你会发现有意思的问题
假如你把return result放在if里面，你会只得到第一个字符
放在外面只能得到最后一个字符，前面的字符会变成**问号乱码**
**老师老师，这是为什么呢？**
- 得到第一个是你判断到第一个就一把子return了，谁还管你后面有没有
- 得到最后一个是你每次都要用malloc重新申请一个动态内存，前面的给一把子清零了，谁还知道你前面的是什么
---
## version 3
```c
char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    char* result;
    if (strsSize == 0) return strdup("");
    if(strsSize != 0){
        for(int j=0; j < strlen(strs[i])-1; j++){
            for(i=0; i<strsSize-1; i++){
                if(strs[i][j]!=strs[i+1][j]&&j==0)
                    return strdup("");
                if(strs[i][j]!=strs[i+1][j])
                    break;
                if(strs[i][j]==strs[i+1][j]&&((i+1) == strsSize-1)){
                    result = (char*)malloc(j+2);
                    for(int k=0;k<=j;k++)
                        result[k]=strs[i][k];
                    result[j+1]='\0';
                }
            }
        }
        return result;
    }
    return 0;
}
```
针对上面那个问题，我选择了一个极其复杂的解决方案
每判断一次相等，就申请一次**动态内存，把前面的存进去**
但是这样又遇到一个问题：**时间超了**
本来应该只有很短时间，结果每次都要malloc，太复杂了

---

写了这么这么多行，改了这么这么多次，才发现原来是自己的思路太太太复杂了TT
## standard version
```c
char* longestCommonPrefix(char** strs, int strsSize) { 
	char* s0 = strs[0]; 
	for (int j = 0; s0[j]; j++) { // 从左到右 
		for (int i = 0; i < strsSize; i++) { // 从上到下 
			if (strs[i][j] != s0[j]) { // 这一列有字母缺失或者不同 
				s0[j] = '\0'; // 0 到 j-1 是公共前缀 
				return s0; 
			} 
		} 
	} return s0; 
} 
```
我发现他的思路和我很不一样，并直接体现在了代码的简洁度上
[标准思路](https://leetcode.cn/problems/longest-common-prefix/solutions/2801713/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-478q)
1. 我每次都是把这一个字符串和下一个比较，而人家直接和第一个比较，只要不一样就结束
2. 而他结束的方式非常值得学习，我的想法是重新定义一个字符串指针，第一个字符写在第0位，以此类推，在最后一个后面加上\0，但是这样老是用malloc太麻烦了。而他的方法连malloc都不用，只需要把开始不一样的那一位变成\0，再直接输出原来的字符串，甚至不需要另外申请动态内存，直接用原来字符的内存
3. 这种方法甚至对只有一个字符串的情况也适用，直接结束循环，return s0，一把子秒了


默写的时候有三个地方出错：
1. 没写第一个return s0，为什么一定要写呢，如果不写的话，循环会继续进行，这会导致如果下面的字符串比第一个短，程序会继续进行，从而导致j越界访问
2. 第一个for的判断条件并非s0，而是s0\[j]，s0不会是空指针
3. 第二个return的位置错了