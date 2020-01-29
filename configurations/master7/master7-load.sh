./prefixdbd -u wwwrun -d -C master7-load.conf --startup-options="prefixdb1:load=8192:setnx=true" --pid-dir=/logs/ $@
tail -f /logs/prefixdb-master7.log

