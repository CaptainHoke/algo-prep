package main

import (
	"fmt"
	"sort"
	"strings"
)

// LC Daily
// 451. Sort Characters By Frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters.
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Constraints:
// - 1 <= s.length <= 5 * 10^5
// - s consists of uppercase and lowercase English letters and digits.

func frequencySort(s string) string {
	packedFreqToChar := make([]uint32, 128)

	for i := uint32(0); i < uint32(len(packedFreqToChar)); i++ {
		packedFreqToChar[i] = i
	}

	for i := 0; i < len(s); i++ {
		newFreq := ((packedFreqToChar[s[i]] >> 16) + 1) << 16
		symbol := (packedFreqToChar[s[i]] << 16) >> 16
		packedFreqToChar[s[i]] = newFreq | symbol
	}

	sort.Slice(packedFreqToChar, func(l, r int) bool {
		return packedFreqToChar[r] < packedFreqToChar[l]
	})

	// TODO: Replace with byte arrays
	var sb strings.Builder
	for _, f2c := range packedFreqToChar {
		if f2c>>16 == 0 {
			continue
		}
		letter := rune((f2c << 16) >> 16)
		substr := strings.Repeat(string(letter), int(f2c>>16))
		sb.WriteString(substr)
	}

	return sb.String()
}

func main() {
	fmt.Println(frequencySort("tree"))
	fmt.Println(frequencySort("aaaccc"))
	fmt.Println(frequencySort("Aabb"))
}
