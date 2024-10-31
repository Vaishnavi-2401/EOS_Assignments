#Write a program to print the table of a given number.

#!/bin/bash


echo -e -n "Enter the Number : "
read num

i=1

while [ $i -le 10 ]

do
	res=`expr $i \* $num`

	echo "$res"

	i=`expr $i + 1`

done
