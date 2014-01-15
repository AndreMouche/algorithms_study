/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-19
 * Time: 下午8:55
 * To change this template use File | Settings | File Templates.
 */
package exercise08

import (
	"testing"
	"fmt"
)

func TestA(t *testing.T) {
	list := NewList()
	for loop := 0; loop < 10; loop ++ {
		list.Insert(loop)
	}
    list.Print()
	for loop := 0; loop < 10; loop ++ {
		item := list.Search(loop)
		if item == nil {
			t.Error("Should not be nil here")
		}

		success := list.Delete(loop)
		if success == false {
			t.Error("Should success here")
		}

		item = list.Search(loop)
		if item != nil {
			t.Error("Should be nil here")
		}

		fmt.Println("Delete ",loop)
		list.Print()
	}
}



