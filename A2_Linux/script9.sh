read -p "Enter a partition: " part1
read -p "Enter ${part1} partition size: " part1_size
read -p "Enter a partition: " part2
read -p "Enter ${part2} partition size: " part2_size
echo "Partition ${part1} size is: ${part1_size} GB"
echo "Partition ${part2} size is: ${part2_size} GB"
echo "---------------------------------------------
Total disk size is: $((part1_size + part2_size)) GB
---------------------------------------------"
