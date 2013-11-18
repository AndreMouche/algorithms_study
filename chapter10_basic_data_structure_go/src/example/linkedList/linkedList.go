/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-18
 * Time: 下午7:56
 * To change this template use File | Settings | File Templates.
 */
package linkedList

type LinkedItem struct {
	pre *LinkedItem
	value int
	next *LinkedItem
}

type LinkedList interface {
	Search(k int) *LinkedItem
	Insert(value int)
	Delete(value int) bool
}

