#!/bin/bash

c=$1
if [[ $c == ? ]];
    then echo "To delete all files you should type suffixes of the files. Then type day when file was modified in order to delete this file." >&2; exit 1
fi
read -p "Type suffix = " a
if ! [[ $a =~ ^[a-z]+$ ]];
   then echo "error: Not a suffix" >&2; exit 1
fi

read -p "Type time =" b
if  ! [[  $b =~ ^[0-9]+$ ]];
    then echo "error: Not a number" >&2; exit 1
fi
find . -type f -name "*$a" -mtime +"$b" -delete
# -mmin +n - minutes
# -mtime +n - days
