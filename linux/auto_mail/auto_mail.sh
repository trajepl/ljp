#! /bin/bash
cat user_info1 | while read LINE
do
    str=$LINE
    array=(${str//,/ })
    target_mail=${array[0]}@stu.suda.edu.cn
    title="username,passwd"
    content=st$LINE

    echo $content | mail -s $title $target_mail
    sleep 1m
done
