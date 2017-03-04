#!/usr/bin/python
#encoding:utf-8

import os
import sys 
import urllib
from multiprocessing import Pool
from multiprocessing import Process

def speed(downloaded, data, remota_data):
    per = 100.0 * downloaded * data / remota_data
    if per > 100:
        per = 100
    out = open('./' + str(os.getpid()) + '.ret', 'w')
    out.write('\r')
    out.write('%.2f%% ' %per)
    out.flush()


def download(url, filename):
    urllib.urlretrieve(url, str(os.getpid()) + filename +'.zip', speed)


def start():
    pool = Pool(30)
    link = open('./link.txt', 'r')
    result = []
    for line in link.readlines():
        list = line.strip().split(' ')
        url = list[0]
        filename = list[1]
        if url != 'none':
            pool.apply_async(download, args = (url, filename,))
    pool.close()
    pool.join()

start()
