/*
Reverse a given stack of integers using recursion.
Note:
You are not allowed to use any extra space other than the internal stack space used due to recursion.
You are not allowed to use the loop constructs of any sort available as handy. For example: for, for-each, while, etc. 
The only inbuilt stack methods allowed are:
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
*/

#include <bits/stdc++.h>
void pushLast(stack<int>& st, int ele) {
   if (st.empty()) {
       st.push(ele);
       return;
   }

   int top = st.top();
   st.pop();
   pushLast(st, ele);
   st.push(top);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.size() == 0 || stack.size() == 1)
        return;
    
    int first = stack.top();
    stack.pop();
    reverseStack(stack);
    pushLast(stack, first);
}


