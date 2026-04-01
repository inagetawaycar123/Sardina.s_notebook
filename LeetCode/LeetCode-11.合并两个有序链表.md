---
date: 2026-04-01
tags:
  - C语言
  - LeetCode
  - 链表
---
# 原题
[合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/solutions/226408/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/?envType=problem-list-v2&envId=linked-list)

## 解法

```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if(!list1) return list2;

    if(!list2) return list1;

    if(list1->val < list2->val){

        list1->next = mergeTwoLists(list1->next, list2);

        return list1;

    }else{

        list2->next = mergeTwoLists(list1, list2->next);

        return list2;

    }

}
```
