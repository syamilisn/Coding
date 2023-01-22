tcount=0
for i in `ls *.txt`;do
	tcount=`expr $tcount + 1`
	echo "$tcount) $i"
done
echo "--------------------------------
Total No. of text file: $tcount"
	
