#Write a program to find the factorial of given number.

#!/bin/bash

read -p "Enter a number: " num
fact=1
for ((i=2; i<=num; i++)); do
fact=$((fact * i))
done
echo "Factorial of $num is $fact."
