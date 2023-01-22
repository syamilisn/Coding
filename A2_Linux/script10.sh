read -p "Enter ping count: " count
read -p "Enter IP address: " IP
read -p "Enter File name: " fname
cmd=`ping -c $count $IP > $fname`
echo "$cmd"
