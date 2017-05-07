package main

import (
	"errors"
	"fmt"
)

func stack(capS int) (func(interface{}) error, func() (interface{}, error)) {
	s := make([]interface{}, 0, capS)

	push := func(val interface{}) error {
		n := len(s)
		if n >= cap(s) {
			return errors.New("stack is full")
		}
		s = s[:n+1]
		s[n] = val

		return nil
	}

	pop := func() (interface{}, error) {
		n := len(s)
		if n <= 0 {
			return 0, errors.New("stack is empty")
		}
		x := s[n-1]
		s = s[:n-1]

		return x, nil
	}

	return push, pop
}

func conversion(num int, i int) string {
	ret := ""
	push, pop := stack(100)
	for num != 0 {
		push(num % i)
		num = num / i
	}

	for x, err := pop(); err == nil; x, err = pop() {
		ret += fmt.Sprintf("%v", x)
	}
	return ret
}

// func main() {
// 	print(conversion(1348, 8))
// }
