#echo "[ 10 -eq 10 ]: `[ 10 -eq 10 ]; echo $?`"
#echo "[ 10 -eq 20 ]: `[ 10 -eq 20 ]; echo $?`"
#echo ""whoami" == "root": `[ whoami == "root"]; echo $?`"
#echo "If else statement:"
read -p "Enter n value: " n
if [ $n -gt 500 ]
then
	echo "True block"
	echo "n value = $n"
	n=`expr $n + 100`
else
	echo "False block"
	n=`expr $n - 10`
fi
echo "updated n value = $n"
