#!/bin/bash

display_menu()
{
    echo "Menu:"
    echo "1. Date"
    echo "2. Cal"
    echo "3. Ls"
    echo "4. Pwd"
    echo "5. Exit"
}

echo -n -e "Enter your Choice : "
read choice

    case "$choice" in

        1) echo "Enter the date : $(date) "
				;;

        2) echo "Enter the Calendar : "
				read cal
				cal $cal
				;;

        3) ls
				;;

        4) pwd
				;;

        5) exit
				;;

        *) echo "Invalid choice!"
				;;

    esac
