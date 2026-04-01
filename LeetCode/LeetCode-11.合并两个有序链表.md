---
date: 2026-04-01
tags:
  - C语言
  - LeetCode
  - 链表
---
# 原题

[合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/solutions/226408/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/?envType=problem-list-v2&envId=linked-list)

>将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
```

## 解法

### 解法一：递归

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

### 解法二：遍历

```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode prehead;
    struct ListNode* prev;

    while(list1 && list2){
        if(list1->val <= list2->val){
            prev->next = list1;
            list1 = list1->next;
        }else{
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }

    prev->next = list1 ? list1 : list2;
    return prehead.next;
}
```
