/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-11-25
 * Time: 下午7:42
 * To change this template use File | Settings | File Templates.
 */
package exercise02
import (
	"launchpad.net/gocheck"
	"testing"
)

func Test(t *testing.T) {gocheck.TestingT(t) }

type MyStackTestSuite struct {
	myStack *SingleListStack
}

var _ = gocheck.Suite(&MyStackTestSuite{})

func (self *MyStackTestSuite) SetUpTest(c *gocheck.C) {
	self.myStack = NewSingleListStack()
}

func (self *MyStackTestSuite) TearDownTest(c *gocheck.C) {

}


func (self *MyStackTestSuite) Test(c *gocheck.C) {
	for i := 0; i < 10; i ++ {
		self.myStack.Push(i)
	}

	expected := 9
	for {
		if self.myStack.IsEmpty() == true {
			break
		}
		top , err := self.myStack.Pop()
		c.Assert(err,gocheck.IsNil)
		c.Assert(expected,gocheck.Equals,top)
		expected --
	}
}




