#Write a Program to find the greatest of three numbers

#!bin/bash


echo -e -n "Enter the three numbers : "
read n1 n2 n3


function find_greatest()
{
	greatest=$1
	if [[ $2 -gt $greatest ]];
	then
	greatest=$2
	fi

	if [[ $3 -gt $greatest ]];
	then
	greatest=$3
	fi

	echo $greatest
}


greatest_number=$(find_greatest $n1 $n2 $n3)

echo "The greatest number : $greatest_number"
