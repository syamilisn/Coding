read -p "Enter shell name: " shell
case $shell in
bash)	profile="bashrc";;
ksh)	profile="kshrc";;
csh)	profile="cshrc";;
*)	echo "Not matched. Default shell:"
	shell="/bin/nologin"
	profile="/etc/profile"
esac
echo "Shell name: $shell; Profile name: $profile"
