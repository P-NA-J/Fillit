#! /bin/bash

NB_CONTENU=$1
shift
i=0
while [ $i -le $((NB_CONTENU-1)) ] ; do
  TAB[$i]=$1
  echo $i
  shift
  i=$(($i+1))
done

for i in `seq {2; 4 ; 10}` ; do \
    echo $i; \
done