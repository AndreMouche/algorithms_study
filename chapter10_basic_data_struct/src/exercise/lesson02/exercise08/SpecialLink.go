/**
 * 如何对每个元素仅用一个指针np[x]（而不是两个指针next和prev）来实现双链表。
 * 假设所有指针值都是k位的整型数，且定义np[x]=next[x]XOR prev[x],即next[x]
 * 和prev[x]的k位异或（NIL用0表示）.注意要说明访问表头所需的信息，以及如何实现在
 * 该表上的SEARCH，INSERT和DELETE操作。如何在O（1）时间内实现这样的表。
 * User: fun
 * Date: 14-1-14
 * Time: 下午8:18
 * To change this template use File | Settings | File Templates.
 * 搞不定地址与int的互转啊，求大神帮忙啊啊啊啊啊啊
 */
package exercise08

import (
	"fmt"
	"unsafe"
)


type Item struct {
	np int
	value int
}

type List struct {
	head *Item
}

func NewList()*List {
	return &List{&Item{np:0,value:0}}
}

func (self *List) Insert(value int) {
	node := &Item{value:value}
	headAddress := (unsafe.Pointer(self.head))
	second := (unsafe.Pointer(headAddress^unsafe.Pointer(nil))).(*Item)
	node.np := int(second) ^ (int(self.head))
	if second != nil {
		tmpnn := second.np ^ int(self.head)
		second.np = tmpnn ^ int(node)
	}
}

func (self *List) Search(value int) *Item {
	var prev *Item
	prev = nil
	for p:=self.head;p!=nil; {
		if p.value == value {
			return p
		}
	    p = int(prev)^p.np
		prev = p
	}
	return nil
}

func (self *List) Delete(value int)bool{
	var prev *Item
	prev = nil
	for p:=self.head;p!=nil; {
		if p.value == value {
		   pprev := 0
		   if prev != nil {
			   pprev = prev.np ^ int(p)
		   }
		   next := (p.np ^ int(prev)).(*Item)
		   prev.np = int(next) ^ pprev

		   nnext := 0
		   if next != nil {
			  nnext = next.np * int(p)
			  next.np = int(prev) ^ nnext
		   }
			return true
		}
		p = int(prev)^p.np
		prev = p
	}
	return false
}

func (self *List) Print() {
	var prev *Item
	fmt.Println()
	prev = nil
	for p:=self.head;p!=nil; {
		fmt.Print(p.value)
		pnext := int(prev)^p.np
		prev = p
		if pnext != 0 {
			p = pnext.(*Item)
		} else {
			p = nil
		}
	}
	fmt.Println()
}



