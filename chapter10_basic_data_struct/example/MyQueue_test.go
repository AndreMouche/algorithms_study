/**
 * Created with IntelliJ IDEA.
 * User: fun
 * Date: 13-10-14
 * Time: 下午8:55
 * To change this template use File | Settings | File Templates.
 */
package example

import (
	. "launchpad.net/gocheck"
	"testing"
)

func Test(t *testing.T) {TestingT(t) }

type MyQueueTestSuite struct {
	myQueue *MyQueue
}

var _ = Suite(&MyQueueTestSuite{})

func (s *MyQueueTestSuite) SetUpTest(c *C) {
	s.myQueue = NewMyQueue(100)
}

func (s *MyQueueTestSuite) TearDownTest(c *C) {

}

func (s *MyQueueTestSuite) TestMyQueue(c *C) {
	for i := 0; i < 10; i ++ {
		s.myQueue.EnQueue(i)
	}

	value := 0
	for s.myQueue.Empty() {
		curValue, err := s.myQueue.DeQueue()
		if err != nil {
			c.Error(err)
		}

		c.Assert(curValue, Equals, value)

		value ++
		//fmt.Println()

	}
}


