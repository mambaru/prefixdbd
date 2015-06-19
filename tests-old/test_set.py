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
  while(1):
    req = json.dumps({
        'method':'set',
        'id':1,
        'params':{
          "email_fs_faces_sender_last_uid1":1234567
        }
    })+"\r\n"
    print req
    cli.send(req)
    data = "/**/"
    while data[-2:]!='\r\n':
      data += cli.recv(1024*1024)
    print(data)
    result = json.loads(data[4:])
    break

