package main

import (
	"fmt"
	"strings"
)

// LC Daily
// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Constraints:
// - 1 <= strs.length <= 104
// - 0 <= strs[i].length <= 100
// - strs[i] consists of lowercase English letters.

func compressWord(str string) string {
	var letters [26]int
	for _, c := range str {
		letters[c-'a']++
	}

	var sb strings.Builder
	for i, c := range letters {
		if c == 0 {
			continue
		}
		sb.WriteRune(rune('a' + i))
		sb.WriteString(fmt.Sprintf("%d", c))
	}

	return sb.String()
}

func groupAnagrams(strs []string) [][]string {
	result := map[string][]string{}

	for _, s := range strs {
		key := compressWord(s)
		result[key] = append(result[key], s)
	}

	var arr [][]string
	for _, v := range result {
		arr = append(arr, v)
	}
	return arr
}

func main() {
	fmt.Printf("%v", groupAnagrams([]string{"eat", "tea", "tan", "ate", "nat", "bat"}))
}
