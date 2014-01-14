/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-19
 * Time: 下午8:55
 * To change this template use File | Settings | File Templates.
 */
package exercise07

import (
	"testing"
)

func TestA(t *testing.T) {
	list := NewSingleList()
	for loop := 0; loop < 10; loop ++ {
		list.Insert(loop)
	}

	list.Print()
	list.Reverse()
	list.Print()
}



