i=0
while [ $i -lt 5 ]
do
	echo "i value is $i"
	echo "`date`"
	#sleep 2
	i=`expr $i + 1`
done

echo

#read -p "Enter i value: " i
i=0
while [ $i -lt 5 ]
do
	echo "i value is $i"
	i=`(($i + 1))`
done
