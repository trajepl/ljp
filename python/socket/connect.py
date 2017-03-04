#!/usr/bin/python
# Baseic Connection Example - Chapter2 - connect.py
import socket
print("Creating socket...")
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Done!")

print("Connecting ro remote host...")
s.connect(("www.baidu.com", 80))
print("Done!")
