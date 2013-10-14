/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-10-14
 * Time: 下午8:22
 * To change this template use File | Settings | File Templates.
 */
package example

import "errors"

type MyQueue struct {
	head int
	tail int
	length int
	item []int
}

func NewMyQueue(length int) *MyQueue {
	qu := &MyQueue{
		head : 0,
		tail : 0,
		length : length,
		item : make([]int,length),
	}

	return qu
}


func (this *MyQueue) EnQueue(elem int) error {
	if this.tail == this.length {
		return errors.New("out of length");
	}

	this.item[this.tail] = elem
	this.tail += 1

	return nil
}


func (this *MyQueue) DeQueue() (int,error){
	if this.tail == this.head {
	    return 0, errors.New("Empty Queue")
	}

	value := this.item[this.head]
	this.head ++
	return value,nil
}

func (this *MyQueue) Empty() bool{
	return this.head == this.tail
}
