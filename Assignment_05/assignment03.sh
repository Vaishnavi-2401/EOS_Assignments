#Write a shell script to accept the name from the user and check whether user entered name is file or directory. If name is file display its size and if it is directory display its contents.

#!/bin/bash

echo -e -n "enter path :"
read path

if [ -e $path ]
then
	if [ -f $path ]
	then
		echo "It is a Regular file"
		echo -e -n "File type : " 
		stat -c %F $path
		echo "Inode No : "
		stat -c %i $path
	elif [ -d $path ]
	then
		echo "It is directory"
		echo "Contents of directory : "
		ls
	else
		echo "Invalid"
	fi
else
	echo "Path does not exist"
fi
