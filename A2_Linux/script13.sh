if [ `ps -e | wc -l` -gt 100 ]
then
	echo "Total no. of process count is : `ps -e|wc -l`"
	echo "Last 10 process details:-"
	sleep 3
	ps -e|tail
	sleep 5
	clear
else
	echo "Total no. of process count is : `ps -e|wc -l`"
	echo "Last 10 process details:-"
	ps -e|head
	sleep 5
	clear
fi
