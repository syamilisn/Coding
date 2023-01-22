pin=1234
#read -p "Enter Login Pin: " login
i=0
while [ $i -eq 3 ]
do
	i=`expr $i + 1`
	read -p "Enter Login Pin: " login

	if [ $login -eq $pin ];then 
		echo "Login success!!"
		break
	else
		echo "Try again!"
		#read -p "Enter Login Pin: " login
	fi
done
