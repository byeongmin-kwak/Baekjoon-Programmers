import sys
sys.setrecursionlimit(10**9)

def postorder(start, end):
    if start > end:
        return

    root = preorder[start]

    right_subtree_start = end + 1
    for i in range(start + 1, end + 1):
        if preorder[i] > root:
            right_subtree_start = i
            break
    
    postorder(start + 1, right_subtree_start - 1)
    postorder(right_subtree_start, end)
    print(root)

preorder = []

while True:
    try:
        preorder.append(int(input()))        
    except:
        break
    
postorder(0, len(preorder) - 1)