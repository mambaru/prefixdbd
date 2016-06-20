echo "***************************************************************"
echo "** запуск с полным копированием с мастера ldb2:master2       **"
echo "***************************************************************"

port=23513
addr=ldb2

master=master2
slave=slave2
user=`whoami`

src=$user@$addr:/monamour/prefixdb/$master/*
dst=/monamour/prefixdb/$slave/

sudo chown -R $user:users $dst
rm -f -r $dst
(echo "db 600"; sleep 1) | telnet $addr $port 2> /dev/null
rsync  --progress -rh $src $dst
(echo "cb"; sleep 1) | telnet $addr $port 2> /dev/null
sudo chown -R wwwrun:www $dst

