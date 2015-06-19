#!/usr/bin/env python

import socket
import subprocess
import sys
import time
import json
import math
import config

if __name__ == '__main__':
  #cli.connect(("cdaemon16", 22510))
  while(1):
    cli = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    cli.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    print("---1---")
    cli.connect(config.server)
    cli.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    print("---2---")
    req = json.dumps({
          'method':'dec_add',
          'id':1,
          'params':{
            'dec':{
              'key2':2,
              'key3':-3
            },
            'def':{
              'key1':10,
              'key2':100,
              'key3':1000
            }
          }
      })+"\r\n"
    print req
    cli.send(req)
    data = "/**/"
    print("---3---")
    while data[-2:]!='\r\n':
      data += cli.recv(1024*1024)
      print("3.1" + data)
    print(data)
    print("---4---")
    cli.close()
    break
  result = json.loads(data[4:])

