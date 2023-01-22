while :
do

	echo "********System Info*********
	1. Kernel
	2. Process
	3. Date and time
	4. Login name and hostname
	5. quit "
	read -p "Enter Choice >> " choice

	case $choice in
		1) echo Kernel `uname -a`;;
		2) echo Process `ps -f`;;
		3) echo Date and time `date`;;
		4) echo Login name and hostname `whoami hostname`;;
		5) echo quit;exit;;
		*) echo Sorry $choice is invalid choice; exit
	esac
done
