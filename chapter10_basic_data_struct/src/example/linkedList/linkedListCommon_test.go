/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-18
 * Time: 下午8:22
 * To change this template use File | Settings | File Templates.
 */
package linkedList

import (
	"testing"
)

func TestA(t *testing.T) {
	list := NewLinkedListSentinel()
	for loop := 0; loop < 10; loop ++ {
		list.Insert(loop)
	}

	for loop := 0; loop < 10; loop ++ {
		item := list.Search(loop)
		if item == nil {
			t.Error("Item Should not be nil")
		}

		flag := list.Delete(loop)
		if flag == false {
			t.Error("Delete Failed")
		}

		item = list.Search(loop)
		if item != nil {
			t.Error("Item should be nil")
		}
	}
}

