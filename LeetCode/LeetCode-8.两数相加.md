---
tags:
  - LeetCode
  - C语言
  - 链表
date: 2025-11-24
---
## 原题
[两数相加](https://leetcode.cn/problems/add-two-numbers/?envType=problem-list-v2&envId=linked-list)

>给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。
>
>请你将两个数相加，并以相同形式返回一个表示和的链表。
>
>你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


## 思路
不难，但是很多很多细节。
链表一般返回什么？
头指针
怎么排除各种意外情况？
链表结束了怎么处理？
如何把进的那一位传递给下一个循环？
最后一位呢？


```c
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL, *tail = NULL;
    int carry = 0;
    for(int n1, n2, sum; l1 || l2;){
        n1 = l1? l1->val : 0;
        n2 = l2? l2->val : 0;
        sum = (n1 + n2 + carry) % 10;
        if(!head){
            head = malloc(sizeof(struct ListNode));
            tail = head;
            tail->val = sum;
            tail->next = NULL;
        }else{
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum;
            tail = tail->next;
            tail->next = NULL;
        }

        carry = (n1 + n2 + carry) / 10;

        if(l1){
            l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }
    }

    if(carry){
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail = tail->next;
        tail->next = NULL;
    }
    return head;
}
```



