#!/bin/bash

MAX=0
I=0
D=0

make fclean

if [[ ($1 = 'ft') ]]
then
    make ft
    ./ft
    if [[ ($2 = 'leaks') ]]
    then
    leaks ft
    fi
elif [[ ($1 = 'std') ]]
then 
    make std
    ./std
else 
    make all
    ./std > std_output.txt
    ./ft > ft_output.txt

    exec 3<> ft_output.txt
    exec 4<> std_output.txt 
    MAX=$( awk ' { if ( length > x ) { x = length } }END{ print x }' ft_output.txt )
    while IFS= read -r lineA <&3 && IFS= read -r lineB <&4; do
        I=$(echo "${#lineA}")
        D=$(expr $MAX - $I)
        echo -n "$lineA" >> output.txt
        printf '%*s' $D >> output.txt
        echo -n "|      " >> output.txt
        echo "$lineB" >> output.txt
    done <ft_output.txt <std_output.txt

    if cmp -s std_output.txt ft_output.txt
    then echo -e "\n\033[1;31m Test OK\n"
    else
        diff std_output.txt ft_output.txt > diff.txt
        echo -e "\n\033[1;31m Test KO\n"
    fi
    rm std_output.txt ft_output.txt
fi

