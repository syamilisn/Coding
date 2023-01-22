echo "Activity: Test if login in root user or not"
if [ `whoami` == "root" ]
then
	echo "`cat /etc/issue`"
elif [ `whoami` == "ee213031" ]
then
	echo "`cat /etc/issue`"
else
	echo "sorry you're not the root user."
fi
