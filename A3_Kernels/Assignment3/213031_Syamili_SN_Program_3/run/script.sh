echo "/*
* Date       : `date +%d-%m-%Y`
* Version    : `uname -v`
* Release    : `uname -r`
*
* Modulename : ${1}
* Description: ${2}
*/
" >${1}.c
filename=`ls ${1}*`
if [ `ls ${filename}` ];then
	echo "${1} creation success."
	echo "
#include \"run/headers.h\"

MODULE_AUTHOR(\"Syamili S N\");
MODULE_DESCRIPTION(\"${2}\");
MODULE_LICENSE(\"Dual MIT/GPL\");
MODULE_VERSION(\"0.1\");

" >> ${filename}
	cat run/template.c >> ${filename}
else
	echo "${1} creation failed."
fi
