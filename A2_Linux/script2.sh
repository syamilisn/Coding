echo "************************* File System Details *************************"
part_name="/dev/sda1"
fstype="xfs"
fmount="/D1"
fdisk="150M"
echo "About ${part_name} partition details:-
-----------------------------------------------------------------------
Partition name: ${part_name} File System Type: ${fstype}
-----------------------------------------------------------------------
mount point directory: ${fmount} ${part_name} disk size: ${fdisk}
-----------------------------------------------------------------------"
