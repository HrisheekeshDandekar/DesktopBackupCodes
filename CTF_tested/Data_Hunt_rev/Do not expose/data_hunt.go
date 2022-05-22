package main

import (
	"fmt"
	"os"
)

func printFlag() {
	flag := []int{
		126, 97, 123, 96, 127, 105,
		75, 92, 78, 115, 106, 57, 124,
		87, 120, 100, 59, 60, 123, 59, 41, 117,
	}

	for i := 0; i < len(flag); i++ {
		fmt.Print((string)(flag[i] ^ 0x8))
	}
}

func main() {

	os.Exit(0)
	printFlag()

}
