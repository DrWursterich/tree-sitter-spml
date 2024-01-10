#!/bin/env bash

dir="$(dirname "$0")"

tree-sitter generate
if [ ! $? -eq 0 ]; then
	exit 1
fi

cargo build
if [ ! $? -eq 0 ]; then
	exit 1
fi

test_amount="$(ls "$dir/test" | wc -l)"
failures=0

echo
echo "found $test_amount tests"
echo

while read line; do
	echo -n "$(basename "$line")  "
	delta="$(tree-sitter parse "$dir/test/$line/test.spml" | diff -a -d -y --color=always - "$dir/test/$line/expected.txt")"
	if [ $? -eq 0 ]; then
		echo -e "\e[32msuccess\e[0m"
	else
		failures=$(( failures + 1 ))
		echo -e "\e[31mfailure!\e[0m"
		echo "actual <-> expected"
		echo "$delta"
	fi
done < <(ls "$dir/test")

echo

if [ $failures -eq 0 ]; then
	echo -e "\e[32mdone\e[0m"
	echo
	exit 0
fi

if [ $failures -eq 1 ]; then
	echo -e "done, \e[31m1 failure\e[0m"
else
	echo -e "done, \e[31m$failures failures\e[0m"
fi
echo
exit 1

