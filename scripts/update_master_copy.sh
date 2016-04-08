(echo "db 300"; sleep 1) | telnet 0.0.0.0 12345 2> /dev/null
rm ./rocksdb2/*/CURRENT
rsync -auvvc --del ./rocksdb1/ ./rocksdb2/
(echo "cb"; sleep 1) | telnet 0.0.0.0 12345 2> /dev/null
