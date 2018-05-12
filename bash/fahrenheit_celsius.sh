# !/bin/bash

print_usage() {
	echo 'fahrenheit_celsius.sh [-c] [-r NUM] [--] beg end'
	exit 0
}

res=10
given_cel=0

while getopts cr: opt; do
	case $opt in
	c) given_cel=1 ;;
	r) res=$OPTARG ;;
	?) print_usage
	esac
done

shift $((OPTIND - 1))
if [ $# -ne 2 ]; then print_usage; fi

scale="scale=8"
beg=$1
end=$2
step=$(bc <<< "$scale; ($end-($beg)) / $res")

fahr_2_cel() {
	bc <<< "$scale; ($1-32) * (5/9)"
}

cel_2_fahr() {
	bc <<< "$scale; $1 * (9/5) + 32"
}

if [ $given_cel -eq 1 ]; then
	h1="Celsius"
	h2="Fahrenheit" 
	form="cel_2_fahr"
else
	h1="Fahrenheit" 
	h2="Celsius"
	form="fahr_2_cel"
fi

printf "%-10s %10s\n" $h1 $h2

for ((i = 0; i <= $res; i++)); do
	x=$(bc <<< "$scale; $beg + $i * $step")
	y=$(eval "$form $x")
	printf "%-10.2f %10.2f\n" $x $y
done
