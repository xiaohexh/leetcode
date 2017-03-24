#!/bin/bash

# Given a text file file.txt that contains list of phone numbers (one per line), write a one liner bash script to print all valid phone numbers.
#
# You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)
#
# You may also assume each line in the text file must not contain leading or trailing white spaces.
#
# For example, assume that file.txt has the following content:
#
# 987-123-4567
# 123 456 7890
# (123) 456-7890
#
# Your script should output the following valid phone numbers:
#
# 987-123-4567
# (123) 456-7890


TEL_REGEXP1="[0-9]{3}-[0-9]{3}-[0-9]{4}"
TEL_REGEXP2="\([0-9]{3}\) [0-9]{3}-[0-9]{4}"

number1="987-123-4567"
number2="123 456 7890"
number3="(123) 456-7890"
number4="(23) 456-7890"

oldIFS=$IFS

IFS=":"

a=($number1 $number2 $number3 $number4)

for num in ${a[@]}
do
	if [[ $num =~ $TEL_REGEXP1 || $num =~ $TEL_REGEXP2 ]];then
		echo $num "is valid" 
	else
		echo $num "is invalid" 
	fi
done

IFS=$oldIFS
