objectfile=${1}
sourcefile=${1}.java
echo "************************************************************"
javac $sourcefile
java $objectfile
echo "************************************************************"
