Ion Flux Relabeling
===================

Oh no! Commander Lambda's latest experiment to improve the efficiency of her LAMBCHOP doomsday device has backfired spectacularly. She had been improving the structure of the ion flux converter tree, but something went terribly wrong and the flux chains exploded. Some of the ion flux converters survived the explosion intact, but others had their position labels blasted off. She's having her henchmen rebuild the ion flux converter tree by hand, but you think you can do it much more quickly - quickly enough, perhaps, to earn a promotion!

Flux chains require perfect binary trees, so Lambda's design arranged the ion flux converters to form one. To label them, she performed a post-order traversal of the tree of converters and labeled each converter with the order of that converter in the traversal, starting at 1. For example, a tree of 7 converters would look like the following:

   7
 3   6
1 2 4 5

Write a function solution(h, q) - where h is the height of the perfect tree of converters and q is a list of positive integers representing different flux converters - which returns a list of integers p where each element in p is the label of the converter that sits on top of the respective converter in q, or -1 if there is no such converter.  For example, solution(3, [1, 4, 7]) would return the converters above the converters at indexes 1, 4, and 7 in a perfect binary tree of height 3, which is [3, 6, -1].

The domain of the integer h is 1 <= h <= 30, where h = 1 represents a perfect binary tree containing only the root, h = 2 represents a perfect binary tree with the root and two leaf nodes, h = 3 represents a perfect binary tree with the root, two internal nodes and four leaf nodes (like the example above), and so forth.  The lists q and p contain at least one but no more than 10000 distinct integers, all of which will be between 1 and 2^h-1, inclusive.


Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution(5, {19, 14, 28})
Output:
    21,15,29

Input:
Solution.solution(3, {7, 3, 5, 1})
Output:
    -1,7,6,3

-- Python cases --
Input:
solution.solution(3, [7, 3, 5, 1])
Output:
    -1,7,6,3

Input:
solution.solution(5, [19, 14, 28])
Output:
    21,15,29

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.


Solution.java
public class Solution {
    static int binarySearch(int height, int node) {
        //current Binary Tree Size
        int size = (1 << height) - 1;
        //subtree size sum of the left cousins of node
        int subtree = 0;
        if(size <= node)
            return -1;
        while(size != 0) {
            //size of left and right subtree of current parent
            size >>= 1;
            //left cousins are visited first in post-order
            int left = size + subtree;
            //left subtree is visited first in post-order
            int right = left + size;
            //property of post-order traversal
            //parent is always visited just after the right child
            int parent = right + 1;
            if(left == node || right == node)
                return parent;
            if(node > left) //which means its obvious that node is in the current right subtree
                subtree = left;
        }
        return -1;
    }
    public static int[] solution(int h, int[] q) {
        // Your code here
        int n = q.length;
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) {
            ans[i] = binarySearch(h, q[i]);
        }
        return ans;
    }
}
