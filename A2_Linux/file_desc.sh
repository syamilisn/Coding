tcount=0
for i in `ls *.txt`;do
	tcount=`expr $tcount + 1`
	echo "$tcount) $i"
done
echo "--------------------------------
Total No. of text file: $tcount"

scount=0
for i in `ls *.sh`;do
	scount=`expr $scount + 1`
	echo "$scount) $i"
done
echo "--------------------------------
Total No. of script file: $scount"

lcount=0
for i in `ls *.log`;do
	lcount=`expr $lcount + 1`
	echo "$lcount) $i"
done
echo "--------------------------------
Total No. of log file: $lcount"
	
