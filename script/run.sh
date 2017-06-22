## run.sh for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Wed Mar 23 03:21:34 2016 
## Last update Tue Mar 21 17:34:10 2017 Manu
##

#!/bin/sh

cmpt=0
div=`expr $1 / $2`
team=1

while [ $cmpt -lt $1 ] ; do
    ./lemipc $PWD $team &
    cmpt=$(($cmpt+1))
    if [ `echo "$cmpt % $div" | bc` -eq 0 ]
    then
	team=$(($team+1))
    fi
done
