echo "***************************************************************"
echo "** запуск с полным копированием с мастера cdaemon17:master1  **"
echo "***************************************************************"

addr=cdaemon17
port=23503
master=master1
slave=slave1
user=`whoami`
src=$user@$addr:/monamour/prefixdb/$master/*
dst=/monamour/prefixdb/$slave/

sudo chown -R $user:users $dst
rm -f -r $dst
(echo "db 600"; sleep 1) | telnet $addr $port 2> /dev/null
rsync  --progress -rh $src $dst
(echo "cb"; sleep 1) | telnet $addr $port 2> /dev/null
sudo chown -R wwwrun:www $dst
