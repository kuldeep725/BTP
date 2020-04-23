sudo perf stat -I100 -M Summary,Frontend,Frontend_Bandwidth,Memory_BW,Memory_Bound,Memory_Lat,Pipeline -x, -o btree_xinput.csv ./BTree.out 100000000 < input.txt
