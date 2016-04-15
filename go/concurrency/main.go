package main

import (
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	for i := 0; i < 10000; i++ {
		wg.Add(1)
		go func() {
			for i := 1; i < 1000; i *= 2 {
				fmt.Printf("%d\n", i)
			}
			defer wg.Done()
			fmt.Println("Goroutine done...")
		}()
	}
	wg.Wait()
	fmt.Println("All finished, main exiting...")
}
