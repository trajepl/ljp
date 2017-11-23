# 研会报名列表

因为微博评论要```点击查看更多```才可逐渐全部加载，因此没有直接利用python的requests模块来抓取网页，请将评论区评论全部加载以后再进行如下操作。

![click-more][1]

chrome浏览器，```F12```查看网页源码,在图中所示html最顶级tag区域```右击```，然后点击```edit as html```。复制整个html源码到程序目录comment文件夹。
然后运行```rank.py```即可。
并没有加以自然语言处理的知识，程序运行结束之后 请自行检查一下。

![copy-html-file][2]


[1]: https://github.com/trajepl/ljp/blob/master/linux/microblog/pic/click-more.png?raw=true
[2]: https://github.com/trajepl/ljp/blob/master/linux/microblog/pic/copy-html.png?raw=true
