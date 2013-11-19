/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-4
 * Time: 下午8:42
 * To change this template use File | Settings | File Templates.
 */
package specialStack

import (
	. "launchpad.net/gocheck"
	"testing"
	"fmt"
)

func Test(t *testing.T) {TestingT(t) }

type MyQueueTestSuite struct {
	myStack SpecialStack
}

var _ = Suite(&MyQueueTestSuite{})

func (s *MyQueueTestSuite) SetUpTest(c *C) {
	s.myStack = NewSpecialStack(100)
}

func (s *MyQueueTestSuite) TearDownTest(c *C) {

}

func (self *MyQueueTestSuite) TestA(c *C) {
	for i := 0; i < 10; i ++ {
		self.myStack.Push(i)
	}

	expected := 9
	for {
		if self.myStack.IsEmpty() == true {
			break
		}
		top , err := self.myStack.Pop()
		fmt.Println(top)
		c.Assert(err, IsNil)
		c.Assert(expected, Equals, top)
		expected --
	}
}


