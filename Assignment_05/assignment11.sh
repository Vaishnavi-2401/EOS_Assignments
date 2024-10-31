#Write a program to calculate gross salary if the DA is 40%, HRA is 20% of basic salary. Accept basic salary form user and display gross salary (Result can be floating point value).

#!/bin/bash

read -p "Enter the basic salary:" basic
da=$(echo "$basic * 0.40" | bc)
hra=$(echo "$basic * 0.20" | bc)
gross=$(echo "$basic + $da + $hra" | bc)
echo "Gross salary: $gross"
