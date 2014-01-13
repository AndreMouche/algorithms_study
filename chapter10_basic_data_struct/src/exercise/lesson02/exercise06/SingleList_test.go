/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 14-1-13
 * Time: 下午8:43
 * To change this template use File | Settings | File Templates.
 */
package exercise06

import "testing"

func Test(t *testing.T) {
	list1 := NewSingleList()
	list2 := NewSingleList()
	for i := 0; i < 10; i ++ {
		list1.Insert(i)
	}

	for i := 11; i < 20; i ++ {
		list2.Insert(i)
	}

	list1.Print()
	list2.Print()
	list1.Union(list2)
	list1.Print()
}

