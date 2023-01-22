read -p "Enter shell name: " shell
if [ "$shell" == "bash" ]
then
	profile="bashrc"
elif [ "$shell" == "ksh" ]
then
	profile="kshrc"
elif [ "$shell" == "csh" ]
then
	profile="cshrc"
else
	echo "Not matched. Default shell:"
	shell="/bin/nologin"
	profile="/etc/profile"
fi
echo "Shell name: $shell; Profile name: $profile"
