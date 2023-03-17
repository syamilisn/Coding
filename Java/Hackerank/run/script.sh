sourcefile=${1}.java
echo "/*
* Author     : Syamili S N
* Version    : `uname -v`
* Release    : `uname -r`
*
* Modulename : ${1}
* Description: ${2}
*/
" >${1}.java
filename=`ls ${1}*`
echo "
class ${1}
{
	public static void main(String args[])
	{
		System.out.println("");
	}
}
	" >> ${filename}
if [ `ls ${filename}` ];then
	echo "${1} creation success."
	echo "

" >> ${filename}

else
	echo "${1} creation failed."
fi
