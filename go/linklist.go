package main

import (
	"fmt"
	"strings"
)

type node struct {
	val  interface{}
	next *node
}

type linkList struct {
	head *node
	tail *node
	size int
}

func (list *linkList) add(values ...interface{}) {
	for _, value := range values {
		newNode := &node{val: value}
		if list.size == 0 {
			list.head = newNode
			list.tail = newNode
		} else {
			list.tail.next = newNode
			list.tail = newNode
		}
		list.size++
	}
}

func (list *linkList) remove(idx int) {
	if list.size > 0 && !list.inRange(idx) {
		return
	}
	for newNode := list.head; newNode != nil; newNode = newNode.next {
		if idx == 0 {
			list.head = list.head.next
			// gc
			newNode = nil
			break
		} else if idx == 1 {
			deleteNode := newNode.next
			newNode.next = deleteNode.next
			// gc
			deleteNode = nil
			break
		}
		idx--
	}
	list.size--
}

func (list *linkList) insert(idx int, value interface{}) {
	if list.size > 0 && !list.inRange(idx) {
		return
	}

	insertNode := &node{val: value}
	for newNode := list.head; newNode != nil; newNode = newNode.next {
		if idx == 1 {
			insertNode.next = newNode.next
			newNode.next = insertNode
			break
		} else if idx == 0 {
			insertNode.next = newNode.next
			list.head = insertNode
			break
		}
		idx--
	}
	list.size++
}

func (list *linkList) get(idx int) interface{} {
	if list.size > 0 && !list.inRange(idx) {
		return nil
	}
	var ret interface{}
	for newNode := list.head; newNode != nil; newNode = newNode.next {
		if idx == 0 {
			ret = newNode.val
		}
		idx--
	}
	list.size--
	return ret
}

func (list *linkList) inRange(index int) bool {
	return index >= 0 && index < list.size
}

func (list *linkList) str() string {
	ret := "LinkList:\n"
	values := []string{}
	curr := list.head
	for curr != nil {
		values = append(values, fmt.Sprintf("%v ", curr.val))
		curr = curr.next
	}

	ret += strings.Join(values, "-> ")
	return ret
}

// test
func main() {
	linklist := &linkList{}
	linklist.add(123, "a", []int{1, 2, 3})
	linklist.insert(1, "postion 1")
	linklist.remove(2)
	fmt.Printf("%v", linklist.get(2))
	print(linklist.str())
}
