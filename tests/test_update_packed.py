#!/usr/bin/env python

import socket
import subprocess
import sys
import time
import json
import math
import config

if __name__ == '__main__':
  cli = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  cli.connect(config.server)

  req = json.dumps({
      'method':'set',
      'id':1,
      'params': {'key1':json.dumps({'key5':5})}
  })+"\r\n"
  print req
  cli.send(req)
  data = "/**/"
  while data[-2:]!='\r\n':
    data += cli.recv(1024*1024)
  print(data)

  req = json.dumps({
      'method':'update_packed',
      'id':1,
      'params':{
        'key':"key1",
        'set':{
          'key3':3,
          'key4':'value4'
        },
        'inc':{
          'key2':2,
          'key3':-3,
          'key6':1
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
  while data[-2:]!='\r\n':
    data += cli.recv(1024*1024)
  print(data)
  result = json.loads(data[4:]);

