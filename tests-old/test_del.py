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
  #cli.connect(("cdaemon16", 22510))
  req = json.dumps({
      'method':'del',
      'id':1,
      'params':['key1','key2','key3']
  })+"\r\n"
  print req
  cli.send(req)
  data = "/**/"
  while data[-2:]!='\r\n':
    data += cli.recv(1024*1024)
  print(data)
  result = json.loads(data[4:]);

