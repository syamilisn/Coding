sourcefile=${1}.java
echo "/*
* Author     : Syamili S N 		Filename   : ${1}            
* Date       : `date +%d-%m-%Y`         Description: ${2}
*/
" >${1}.java
filename=`ls ${1}*`
echo "
class ${1}
{
        public static void main(String args[])
        {
                System.out.println(\"***************************************************************************\");
        }
}
        " >> ${filename}

if [ `ls ${filename}` ];then
        echo "${1} creation success."

echo "
${1}:
	javac ${filename}
	java ${1}" >> Makefile

echo "${filename}: ${2}" >> README.md
vi ${filename}
make ${1}
else
        echo "${1} creation failed."
fi

