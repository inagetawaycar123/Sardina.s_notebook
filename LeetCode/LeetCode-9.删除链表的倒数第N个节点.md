---
tags:
  - 链表
  - LeetCode
  - C语言
date: 2025-11-24
---
## 原题
[删除链表的倒数第N个节点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solutions/2004057/ru-he-shan-chu-jie-dian-liu-fen-zhong-ga-xpfs/?envType=problem-list-v2&envId=linked-list)

>给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。


## 思路
想直接用双指针，快指针走n步，并且只到达最后一个节点，但是有一个例子怎么都过不去
`head = [1,2] n=1`
`head = [1,2] n=2`
这两个不论怎么调，总会有一个不满足
于是换了一个方法：
```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* slower = head;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast){
        fast = fast->next;
        slow = slow->next;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
        slower = slower->next;
    }
    if(slower != slow){
        slower->next = slow->next;
    }else{
        head = slower->next;
    }
    free(slow);
    return head;
}
```
之所以会成功，是因为不管怎么样，slow永远永远指向被删除的节点

看到题解还有一种方法，是建一个**哨兵头节点**：
```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy = {0, head};
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    while(n--){
        fast = fast->next;
    }
    
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    return dummy.next;
}
```
这么做是为了排除n为链表长度的情况

一个小细节是，最后返回的是`dummy.next`
而不是`head`
也不是`dummy->next`
`head`有时候会被删除
而`->`仅用作指针的访问