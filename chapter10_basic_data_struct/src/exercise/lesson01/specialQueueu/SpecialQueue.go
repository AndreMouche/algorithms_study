/**
   10.1-6 用两个栈实现一个队列的功能
   思路：用两个栈，一个用于队列enStack，一个用于出队列outStack
   EnQueue（x）:
     enStack.push(x)
   DeQueue()
     若outStack当前为空，则将enStack中的元素挨个出栈并依次压入outStack
     然后取最后一个enStack中元素即为当前队首元素

     若outStack非空，直接取出第一个outStack即可


     如上，最坏情况为所有入队元素都进入两个栈一次，即O(2n)

 *
 */
package specialQueueu

import (
	"example/stack"
	"errors"
)

type SpecilQueue struct {
	enStack *stack.MyStack
	outStack *stack.MyStack
}

func NewSpecialQueue(maxLength int) *SpecilQueue {
	return &SpecilQueue{
		enStack:stack.NewMyStack(maxLength),
		outStack: stack.NewMyStack(maxLength),
	}
}

func (self *SpecilQueue) Empty() bool {
	return self.enStack.IsEmpty() && self.outStack.IsEmpty()
}

func (self *SpecilQueue) EnQueue(x int) error {
	return self.enStack.Push(x)
}

func (self *SpecilQueue) DeQueue() (int, error) {
	if self.Empty() {
		return 0, errors.New("Empty queue")
	}

	if self.outStack.IsEmpty() {
		for {
			if self.enStack.IsEmpty() {
				break
			}

			val, _ := self.enStack.Pop()
			self.outStack.Push(val)
		}
	}

	result, err := self.outStack.Pop()
	return result, err
}
