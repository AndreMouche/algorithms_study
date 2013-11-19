/**
 * 10.1-7 用两个队列实现一个栈
 * 思路，一个队列用于入队，另一个队列用于出栈时的中间容器，栈的长度为单个队列可容纳长度。
 * 具体操作为：
 * 初始化：
 * pushQueue = q1
 * A.push 入栈 O(1)：
 *  将数据赛入pushQueue队尾，若pushQueue已满，则返回失败
 * B.pop 出栈,O(len(pushQueue))
 *   若pushQueue非空，则将pushQueue中的数据全部出队并依次塞入另一队列中，将pushQueue最后一个元素出栈
 *   若pushQueue为空，且另一队列非空，则将另一队列切换为pushQueue并按pushQueue为非空时操作
 *   若两个队列都为空，则返回队列为空

 * User: fun
 * Date: 13-11-4
 * Time: PM 8:36
 * To change this template use File | Settings | File Templates.
 */
package specialStack

import (
	"chapter10_basic_data_struct/example/queue"
	"errors"
)

type SpecialStack struct {
	qContainer []queue.MyQueue
	pushQueueId int
	length int           //上限
	currentLength int     //当前长度
}

func NewSpecialStack(length int) (SpecialStack) {
    q1 := queue.NewMyQueue(length)
	q2 := queue.NewMyQueue(length)
	return SpecialStack{qContainer:[]queue.MyQueue{*q1,*q2},
						pushQueueId:0,
						length:length,
						currentLength:0}
}

func (self *SpecialStack)IsEmpty() (bool) {
	return self.currentLength == 0
}

//注意：只能往enQueue
func (self *SpecialStack) Push(item int) error {
	if self.length > self.currentLength { //必须确保当前栈内数据不超过length,否则所有数据将无法出栈
	   self.currentLength ++
	   return self.qContainer[self.pushQueueId].EnQueue(item)
	}
	return errors.New("Is full now")
}

func (self *SpecialStack) Pop() (int,error) {
	if self.IsEmpty() {
		return 0,errors.New("Empty stack")
	}

	if self.qContainer[self.pushQueueId].Empty(){
		self.pushQueueId ^= 1
	}

	otherQueueId := self.pushQueueId ^ 1
	for {
		val,_ := self.qContainer[self.pushQueueId].DeQueue()
		if self.qContainer[self.pushQueueId].Empty(){ //pushQueue的最后一个元数为当前栈的栈头
			self.currentLength --
			return val,nil
		}

		self.qContainer[otherQueueId].EnQueue(val)
	}

	return 0,errors.New("Unknow error")
}


