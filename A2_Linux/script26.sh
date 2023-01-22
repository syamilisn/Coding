test(){
	if [[ $1 == "admin" ]] || [[ $1 == "ADMIN" ]];then
		return 0
	else
		return 1
	fi
}
read -p "Enter a login name: " name
test $name
if [ $? -eq 0 ];then
	echo "Hello $name"
	echo "Login is success"
else
	echo "Sorry $name you're not an admin"
fi
