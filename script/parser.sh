#! /bin/bash 

read var_1

let "n_test = var_1"
let "n_file = $n_test * 26 * 50"

for i in  `seq 1 $n_test` ; do \
	for	j in `seq 1 26` ; do \
		for k in `seq 1 50` ; do \
			./binaire/gen valid $j > Map/valid_$j\_$k; \
			./binaire/gen invalid $j > Map/invalid_$j\_$k; \
			var1=$(./fillit Map/valid_$j\_$k); \
			var2=$(./fillit Map/invalid_$j\_$k); \
        	if [ "$var1" = "VALID" ]
        	then
				let "var4 += 1";
            	if [ "$var2" = "INVALID" ]
            	then
                	let "var3 += 1"; \
            	fi
        	fi  
		done \
	done \
done \

if [ "$var3" = "$n_file" ]
then
	echo "Le parser fonctionne"
else
	echo "Le parser ne fonctionne pas"
fi