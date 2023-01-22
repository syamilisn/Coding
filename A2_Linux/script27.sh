pin=1234
i=0
while [ $i -eq 3 ]
do
	i=`expr $i + 1`
	read -p "Enter Login Pin: " login

	if [ $login -eq $pin ];then 
		echo "Login success!!"
		echo "SUCCESS - pin is matched at $i - input entry time is: `date`" >>pin_history.sh
	       	echo "Success pin is matched at $i"	
		break
	else
		echo "Try again!"
		echo "FAILURE - pin $login is not matched at $i - input entry time is: `date`" >>pin_history.sh
	fi
done

if [ $login -ne $pin ];then 
	echo "Sorry your pin is blocked"
	echo "BLOCKED - all three attempts were unsuccessful - input entry time is: `date`" >>pin_history.sh
fi
