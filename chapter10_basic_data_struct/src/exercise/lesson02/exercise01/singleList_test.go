/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-19
 * Time: 下午8:55
 * To change this template use File | Settings | File Templates.
 */
package exercise01

import (
	"testing"
)

func TestA(t *testing.T) {
	list := NewSingleList()
	for loop := 0; loop < 10; loop ++ {
		list.Insert(loop)
	}

	for loop := 0; loop < 10; loop ++ {
		item := list.Search(loop)
		if item == nil {
			t.Error("Item Should not be nil")
		}

		list.Delete(item)

		item = list.Search(loop)
		if item != nil {
			t.Error("Item should be nil")
		}
	}
}



