echo "STORE COMMAND RESULT AS ARRAY VALUES"
cmd1=`date +%D`
cmd2=`cal`
cmd3=`whoami`
cmd4=`hostname`
#arr=(cmd1 cmd2 cmd3 cmd4)
arr=()
echo "array size: ${#arr[@]}"
echo "array content: ${arr[@]}"
arr[0]=$cmd1
arr[1]=$cmd2
arr[2]=$cmd3
arr[3]=$cmd4
echo "array size: ${#arr[@]}"
echo "array content: ${arr[@]}"
