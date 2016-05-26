package leetcode;

import java.util.Stack;

public class ImplementQueueUsingStacks_232 {
    private Stack<Integer> putStack =new Stack<Integer>();
    private Stack<Integer> getStack = new Stack<Integer>();
    
     // Push element x to the back of queue.
    public void push(int x) {
        this.putStack.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        if(this.getStack.isEmpty()==false) {
             this.getStack.pop();
             return;
        }
        while(this.putStack.isEmpty()==false){
            this.getStack.add(this.putStack.pop());
        }
        this.getStack.pop();
    }

    // Get the front element.
    public int peek() {
       if(this.getStack.isEmpty()==false) {
             return this.getStack.peek();
             }
        while(this.putStack.isEmpty()==false){
            this.getStack.add(this.putStack.pop());
        }
        return this.getStack.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
       return this.getStack.isEmpty()&&this.putStack.isEmpty();
    }
}

