
Quadratic Hashing: $H(key) + j^2$ where $j$ = 0 -> N-1
Maane 0, 1, 4, 9, and so on...

Double Hashing:
• Primary hash: H(key) = key % 11  
• Secondary hash: H’(key) = (key % 7) + 1  
• Add 1 because H’(key) must never evaluate to 0


preorder: visit, left, right
postorder: left right visit
inorder: left visit right

Postfix:
nums: append
on op: pop() pop() push(res)

Traversal se trees:
• Where is the root in each traversal?  
- Preorder: First  
- Postorder: Last  
- Inorder: Between the left and right subtrees  
- Level-order: First
![[Screenshot 2026-02-12 at 7.54.36 AM.png|600]]

Unique Tree: Inorder + Another order traversal
Preorder tells you the root
Inorder tells you position: what is to the left and right

In Level Order: root is first, but for any subset of node the one appearing earliest is the root of that subtree
Inorder: same as above

