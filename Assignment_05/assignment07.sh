#Write a Program to find whether a given number is positive or negative

#!/bin/bash


echo "Enter the Number : "
read num


if [ $num -gt 0 ];
then
    echo "$num is Positive"

elif [ $num -lt 0 ];
then
    echo "$num is Negative"

else
    echo "$num is Zero"

fi
