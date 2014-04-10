#!/usr/bin/env python

import socket
import subprocess
import sys
import time
import json
import math
import config

if __name__ == '__main__':
  while(1):
    cli = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    cli.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    cli.connect(config.server)
    #cli.connect(("cdaemon16", 22510))
    req = json.dumps({
        'method':'add',
        'id':1,
        'params':{
          'key1':'value1',
          'key3':'value3'
        }
    })+"\r\n"
    print req
    cli.send(req)
    data = "/**/"
    while data[-2:]!='\r\n':
      data += cli.recv(1024*1024)
    cli.close()
    print(data)
    result = json.loads(data[4:]);
    break
    

