#Write a shell script to display menu like “1. Date, 2. Cal, 3. Ls, 4. Pwd, 5. Exit” and execute the commands depending on user choice.

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
