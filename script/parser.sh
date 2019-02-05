#! /bin/bash 



let "test = var1"
let "var3 = 0"
for	j in `seq 1 26` ; do \
	for k in `seq 1 50` ; do \
		./binaire/gen valid $j > Map/valid_$j\_$k; \
		./binaire/gen invalid $j > Map/invalid_$j\_$k; \
	done \
done \

for	i in `seq 1 26` ; do \
	for j in `seq 1 50` ; do \
		var1=$(./binaire/parser Map/valid_$i\_$j); \
		var2=$(./binaire/parser Map/invalid_$i\_$j); \
        if [ $var1 = "VALID" ]
        then
            if [ $var2 = "INVALID" ]
            then
                echo "YOOOOO" >> debug_Script
            fi
        fi  
	done \
done \
