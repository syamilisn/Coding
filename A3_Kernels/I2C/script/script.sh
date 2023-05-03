echo "/*
* Author     : Syamili S N              Filename   : ${1}
* Date       : `date +%d-%m-%Y`         Description: ${2}
*/
" >${1}.c
filename=`ls ${1}*`
if [ `ls ${filename}` ];then
        echo "${1} creation success."
        echo "
#include \"script/headers.h\"

" >> ${filename}
        cat script/template.c >> ${filename}

echo "
${1}:
	gcc ${filename} -o ${1}.out -w
	./${1}.out" >> Makefile

echo "${filename}: ${2}" >> README.md
vi ${filename}
make ${1}
else
        echo "${1} creation failed."
fi

