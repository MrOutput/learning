package main

import (
	"fmt"
	"github.com/fatih/color"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	if len(os.Args) == 1 {
		err := color.New(color.FgRed).Add(color.Bold)
		err.Println("NO ARGUMENTS PROVIDED.")
		os.Exit(1)
	}
	start := time.Now()
	for i, arg := range os.Args[1:] {
		num := color.GreenString(strconv.Itoa(i + 1))
		arg = strings.ToUpper(arg)
		fmt.Printf("%s: %s\n", num, arg)
	}
	color.Set(color.FgYellow)
	fmt.Printf("Finished in %fs.\n", time.Since(start).Seconds())
	color.Unset()
}
