c=0
while [ $c -lt 3 ] #indicated 2 login attempts
do
	read -p "Enter your login name: " name
	if [ $name == "shyam" ]; then
		echo "Login is success"
		break
	else
		echo "Try-again"
	fi
	c=`expr $c + 1`
done
echo "Next section of code"
echo "End of script"
