read -p "Enter directory name: " dname
if [ -d $dname ];then
	echo "Directory $dname already exists."
	ls -ld $dname
else
	echo "Directory $dname doesn't exist."
	mkdir $dname
	if [ $? -eq 0 ];then
		echo "Directory $dname successfully created."
	else
		echo "Directoru $dname creation failed."
	fi
fi
