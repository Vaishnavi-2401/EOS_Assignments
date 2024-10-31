#Write a shell script to display your LOGIN NAME and HOME directory.

#!bin/bash

echo -e -n "LOGIN NAME : "

whoami

echo "HOME directory : "

pwd

echo -e -n "Current Shell : "

echo "$SHELL"
