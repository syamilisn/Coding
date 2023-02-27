echo "/*
* Author     : Syamili S N
* Program    : ${1}
* Description: ${2}
*/
" >${1}.c
filename=`ls ${1}*`
if [ `ls ${filename}` ];then
	echo "${1} creation success."
	echo "
#include \"run/headers.h\"

" >> ${filename}
	cat run/template.c >> ${filename}
else
	echo "${1} creation failed."
fi
