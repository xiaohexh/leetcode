#!/bin/bash

# Given a text file file.txt, transpose its content.
# You may assume that each row has the same number of columns and each field is separated by the ' ' character.
#
# For example, if file.txt has the following content:
#
# name age
# alice 21
# ryan 30
#
# Output the following:
#
# name alice ryan
# age 21 30

function process() {

	key_list=()
	value_list=()

	file_name=$1
	index=0
	while read line
	do
		i=0
		for word in $line
		do
			if [ $i -eq 0 ];then
				key_list[$index]=$word
			else
				value_list[$index]=$word
			fi
			let i++
		done
		let index++
	done < $file_name

	i=0
	length=${#key_list[@]}
	while [ $i -lt $length ]
	do
		echo -n ${key_list[$i]} " "
		let i++
	done
	echo

	i=0
	while [ $i -lt $length ]
	do
		echo -n ${value_list[$i]} " "
		let i++
	done
	echo
}

if [ $# -lt 1 ];then
	echo "usage: " $0 " file_name"
fi

process $1
