#! /bin/bash 

for	j in `seq 1 26` ; do \
		./binaire/gen valid $j > Map/valid_$j; \
		./fillit Map/valid_$j > Test/Test_$j; \
done \
