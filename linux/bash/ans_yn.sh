#!/bin/bash
# Program:
#     This program shows the user's choice
# History:
#     17/04/26 trajep First release

read -p "Please input(Y/N):" yn
[ "${yn}" == "Y" -o "${yn}" == "y" ] && echo "OK" && exit 0
[ "${yn}" == "N" -o "${yn}" == "n" ] && echo "No" && exit 0
echo "I don't know what your choice is" && exit 0
