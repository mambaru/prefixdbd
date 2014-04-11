#!/usr/bin/env python

import socket
import subprocess
import sys
import time
import json
import math


class leveldb:
  
  def connect(self, addr, port):
    self.cli = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.cli.connect( (addr, port) )
    
  def send(self, req):
    self.cli.send(req+"\r\n")
    data = ""
    while data[-2:]!='\r\n':
      data += self.cli.recv(1024*1024)
    return data[:-2]
  
  def request(self, method, params, id=1):
    req_str = json.dumps({
        'method':method,
        'id':id,
        'params':params
    })
    res_str = self.send(req_str)
    result = json.loads(res_str)
    if 'error' in result:
      raise Exception('jsonrpc error', result['error'])
    return result['result']
    
  def set(self, kv):
    return self.request('set', kv)

  def get(self, keys):
    return self.request('get', keys)

  def has(self, keys):
    return self.request('has', keys)

  def add(self, kv):
    return self.request('add', kv)

  def inc_add(self, kv_inc, kv_def):
    return self.request('inc_add', {'inc':kv_inc, 'def':kv_def} )

  def dec_add(self, kv_inc, kv_def):
    return self.request('dec_add', {'dec':kv_inc, 'def':kv_def} )
  
  def delete(self, keys):
    return self.request('del', keys)
  
  def update_packed(self, key, set_kv, inc_kv, def_kv):
    return self.request('update_packed', {
              'key':key,
              'set':set_kv,
              'inc':inc_kv,
              'def':def_kv
           })
  
  def lua_run(self, lua_code):
    return self.request('lua_run', {"code":lua_code} )

if __name__ == '__main__':
  cli = leveldb()
  cli.connect("0.0.0.0", 12345)
  res = cli.set({'key1':'value1', 'key2':'value2'})
  print "set result: {0}".format(res)
  res = cli.get(["key1", "key2"])
  print "get result: key1={0}, key2={1}".format(res['key1'], res['key2'])
  res = cli.has(["key1", "key2", "keyX"])
  print "has result: key1={0}, key2={1}, keyX={2}".format(res['key1'], res['key2'], res['keyX'])
  res = cli.add({'key1':'value1', 'key2':'value2', 'key3':'value3'})
  print "add result: key1={0}, key2={1}, key3={2}".format(res['key1'], res['key2'], res['key3'])
  res = cli.inc_add({'key1':1, 'key2':2, 'key3':3}, {})
  print "inc_add result: key1={0}, key2={1}, key3={2}".format(res['key1'], res['key2'], res['key3'])
  res = cli.dec_add({'key1':1, 'key2':2, 'key3':3}, {'key1':100, 'key2':100, 'key3':100})
  print "dec_add result: key1={0}, key2={1}, key3={2}".format(res['key1'], res['key2'], res['key3'])
  res = cli.delete(["key1", "key2", "keyY"])
  print "del result: key1={0}, key2={1}, keyX={2}".format(res['key1'], res['key2'], res['keyY'])
  res = cli.dec_add({'key1':1, 'key2':2, 'key3':3}, {'key1':100, 'key2':100, 'key3':100})
  print "dec_add result: key1={0}, key2={1}, key3={2}".format(res['key1'], res['key2'], res['key3'])
  res = cli.update_packed("pack", {"key3": 3, "key4": "value4"}, {'key1':1, 'key2':2, 'key3':3}, {'key1':100, 'key2':100, 'key3':100})
  print "update_packed result: key1={0}, key2={1}, key3={2}, key4={3}".format(res['key1'], res['key2'], res['key3'], res['key4'])
  res = cli.delete(["key1", "key2", "key3", "key4", "key5", "key6", "keyX", "keyY"])
  
  cli.set({"pack":json.dumps({"key5":5})})
  
  res = cli.update_packed(
    "pack", 
    { #set
      "key3": 3, 
      "key4": "value4"
    }, 
    { #inc
      "key3": -3, 
      "key2": 2, 
      "key6": 1
    },
    { #dec
      "key3": 1000,
      "key2": 100,
      "key1": 10
    }
  )
  print "update_packed result: key1={0}, key2={1}, key3={2}, key4={3}, key5={4}, key6={5}".format(res['key1'], res['key2'], res['key3'], res['key4'], res['key5'], res['key6'])
  
  res = cli.delete(["key1", "key2", "key3", "key4", "key5", "key6", "keyX", "keyY"])
  
  res = cli.lua_run(
    '''
      put("key1":"lua")
      put("key2":"lua")
      put("key3":"lua")
      
      counter=1
      function foo(key, value)
        put(key, value + counter)
        counter+=1
      end
      
    '''
  )
  #set_result("\"Done\"")
  print ( "lua result:{0}".format(res) )
  
  res = cli.get(["key1", "key2"])
  print "get result: key1={0}, key2={1}".format(res['key1'], res['key2'])