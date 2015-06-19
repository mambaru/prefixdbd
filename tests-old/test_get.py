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
  #cli.connect(("127.0.0.1", 12345))
  #cli.connect(("cdaemon16", 22510))
  start = time.time()
  i = 0
  count = 1
  while ( i < count ):
    i+=1
    req = json.dumps({
      'method':'get',
      'id':1,
      'params':['key1','key2','key3']
    })+"\r\n"
    print req
    cli.send(req)
    data = "/**/"
    while data[-2:]!='\r\n':
      data += cli.recv(1024*1024)
    break
    
  finish = time.time()
  print(data)
  print(finish - start)
  print( (finish - start)/count )
  result = json.loads(data[4:])
  

