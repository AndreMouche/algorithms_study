package leetcode;

import java.util.LinkedList;
import java.util.Queue;

/**
https://leetcode.com/problems/implement-stack-using-queues/
*/
public class ImplementStackusingQueues {

	private Queue<Integer> q1 = new LinkedList<Integer>();
	private Queue<Integer> q2 = new LinkedList<Integer>();
	private boolean first = true;

	// Push element x onto stack.
	public void push(int x) {
		if (first == true) {
			this.q1.add(x);
		} else {
			this.q2.add(x);
		}
	}

	// Removes the element on top of the stack.
	public void pop() {
		Queue<Integer> f = this.q1;
		Queue<Integer> s = this.q2;
		if (!first) {
			f = this.q2;
			s = this.q1;
		}

		first = !first;
		while (!f.isEmpty()) {
			int val = f.poll();
			if (f.isEmpty()) {
				return;
			}
			s.add(val);
		}
		return;
	}

	// Get the top element.
	public int top() {
		Queue<Integer> f = this.q1;
		Queue<Integer> s = this.q2;
		if (!first) {
			f = this.q2;
			s = this.q1;
		}

		first = !first;
		while (!f.isEmpty()) {
			int val = f.poll();
			s.add(val);
			if (f.isEmpty()) {
				return val;
			}
		}
		return 0;
	}

	// Return whether the stack is empty.
	public boolean empty() {
		return q1.isEmpty() && q2.isEmpty();
	}

}
