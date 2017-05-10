package main

import (
	"fmt"
)

func strStr(haystack string, needle string) int {
	len_hay, len_ned := len(haystack), len(needle)
	if len_hay == 0 && 0 == len_ned {
		return 0
	}
	if len_hay < len_ned {
		return -1
	}
	start, shift := 0, 0
	for start < len_hay {
		for start+shift < len_hay && haystack[start+shift] == needle[shift] {
			shift++
			if shift == len_ned {
				return start
			}
		}

		shift = 0
		start++
	}

	return -1
}

func kmp(haystack string, needle string) int {
	len_ned := len(needle)
	len_hay := len(haystack)
	if len_hay < len_ned {
		return -1
	}
	if len_ned == 0 {
		return 0
	}
	next := getnext(needle)
	idx := 0
	fmt.Println(next)
	for i := 0; i < len_hay; i++ {
		for idx > 0 && haystack[i] != needle[idx] {
			idx = next[idx-1]
		}
		if haystack[i] == needle[idx] {
			idx++
		}
		if idx == len_ned {
			return i - idx + 1
		}
	}

	return -1
}

func getnext(needle string) []int {
	len_ned := len(needle)
	ret := make([]int, len_ned)
	flag := 0
	ret[0] = 0

	for i := 1; i < len_ned; i++ {
		for flag > 0 && needle[i] != needle[flag] {
			flag = ret[flag-1]
		}
		if needle[flag] == needle[i] {
			flag++
		}
		ret[i] = flag
	}
	return ret
}

func main() {
	println(kmp("bbaa", "aa"))
}
