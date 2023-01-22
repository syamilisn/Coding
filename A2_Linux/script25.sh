function kernel(){
	echo kernel
	echo "kernel name: `uname`; Version: `uname -r`"
	uname -a
}
function process(){
	echo kernel
	uname -a
}
function date(){
	echo kernel
	uname -a
}
function login(){
	echo kernel
	uname -a
}
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
		1) kernel;;
		2) process;;
		3) date;;
		4) login;;
		5) echo quit;exit;;
		*) echo Sorry $choice is invalid choice; exit
	esac
done
