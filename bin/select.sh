#!/bin/sh

react_bool(){
    length=$((${#1}+${#2}+3))
    for ((i=0;i<$length;i++))
    do
        printf "\b \b"
    done
}

bool(){
    choix1=$1
    choix2=$2
    value=$1

    printf "\033[0;36m\033[4m$choix1\033[0m | $choix2"
    read -s -n 1 input
    while [ "$input" != "" ]
    do
        case "$input" in
            "C")
                react_bool $choix1 $choix2
                printf "$choix1 | \033[0;36m\033[4m$choix2\033[0m"
                value=$choix2
                ;;
            "D")
                react_bool $choix1 $choix2
                printf "\033[0;36m\033[4m$choix1\033[0m | $choix2"
                value=$choix1
                ;;
        esac
        read -s -n 1 input
    done
    echo $value > bin/res/select.value
    printf "\n"
}