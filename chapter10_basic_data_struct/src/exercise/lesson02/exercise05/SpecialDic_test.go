/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-25
 * Time: 下午8:50
 * To change this template use File | Settings | File Templates.
 */
package exercise05

import (
	"testing"
)

func TestA(t *testing.T) {
	dic := NewDic()
	for i := 0; i < 10; i++ {
		flag := dic.Insert(i, i*2)
		if flag == false {
			t.Error("flag should be true,insert failed")
		}

		flag = dic.Insert(i, i*2)
		if flag == true {
			t.Error("Insert should be failed here")
		}
	}


	for i := 0; i < 10; i++ {
		item := dic.Search(i)
		if item == nil || item.value != i*2 {
			t.Error("item is empty or invalid value")
		}

		flag := dic.Delete(i)
		if flag == false {
			t.Error("Item should delete ok")
		}

		item = dic.Search(i)
		if item != nil {
			t.Error("Item should already be delete here")
		}
	}


}

