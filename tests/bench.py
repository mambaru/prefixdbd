#!/usr/bin/env python

from leveldb import leveldb
from optparse import OptionParser
from threading import Thread, Lock

import json


mutex = Lock()
global_id  = 0

class Config:
    def __init__(self, **entries): 
        self.__dict__.update(entries)

def replace_dlr_array(obj, newval):
  arr = []
  for item in obj:
    arr.append(replace_dlr(item, newval))
  return arr

def replace_dlr_dict(obj, newval):
  dct = {}
  for k in obj:
    dct[replace_dlr(k, newval)] = replace_dlr(obj[k], newval)
  return dct

def replace_dlr_string(obj, newval):
  return obj.replace("$", newval)

def replace_dlr(obj, newval):
  if type(obj)==type({}):
    return replace_dlr_dict(obj, newval)
  elif type(obj)==type([]):
    return replace_dlr_array(obj, newval)
  elif type(obj)==type(u''):
    return replace_dlr_string(obj, newval)
  return obj


def get_id():
  global global_id 
  global mutex
  mutex.acquire()
  global_id = global_id + 1
  id = global_id
  mutex.release()
  return id
  


def call_thread(conf, pos):
  ldb = leveldb()
  ldb.connect( conf.host, conf.port)
  for u in range(conf.repeat):
    for i in range(pos, conf.count, conf.threads):
      for r in range(len(conf.requests)):
        req = replace_dlr(conf.requests[r], str(i) )
        id = get_id()
        resp = ldb.request(req["method"], req["params"], id)
        mutex.acquire()
        print "-----"
        print req
        print resp
        mutex.release()
     

if __name__ == '__main__':
  parser = OptionParser()
  parser.add_option("-f", "--file", dest="filename",
                  help="options json file", metavar="FILE")

  (options, args) = parser.parse_args()
  if not options or not options.filename:
    parser.print_help()
    exit()
    
  
  conf = Config(**json.load( open(options.filename) ))
  threads = []
  for t in xrange(conf.threads):
    thread = Thread(target = call_thread, args = (conf,t) )
    threads.append( thread )

  for t in xrange(conf.threads):
    mutex.acquire()
    print "start", t
    mutex.release()
    threads[t].start()


  for t in xrange(conf.threads):
    threads[t].join()
  '''
  req = replace_dlr(conf.requests[0], "Z")
  print(req)
  
  ldb = leveldb()
  ldb.connect( conf.host, conf.port)
  '''
  