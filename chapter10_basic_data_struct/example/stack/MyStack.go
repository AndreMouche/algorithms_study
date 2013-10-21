/**
 * Example 10.1
 * Page: 119-120
 * User: fun
 * Date: 13-10-21
 * Time: 下午7:21
 */
package stack

import (
	"fmt"
	"errors"
)

type MyStack struct{
	top int
	elem []int
	maxLength int
}

func NewMyStack(length int) (*MyStack) {
	stack := &MyStack{}
	stack.maxLength = length
	stack.top = -1
	stack.elem = make([]int,length,length)
	return stack
}

func (self *MyStack) IsEmpty() bool {
	return self.top == -1
}

func (self *MyStack) Push(x int) error {
	if self.top + 1 >= self.maxLength {
		fmt.Errorf("stack over flow,max length %d",self.maxLength)
	}

	self.top ++
	self.elem[self.top] = x
	return nil
}

func (self *MyStack) Pop() (int, error) {
	if self.IsEmpty() {
		return 0,errors.New("stack is empty now")
	}

	ele := self.elem[self.top]
	self.top --
	return ele , nil
}

