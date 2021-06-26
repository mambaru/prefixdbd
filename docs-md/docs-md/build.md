# Статус сборки 

Сборка мастера осуществляется автоматическиa, поэтому сразу переходим на [деплой](docs-md/deploy.md). Текущий статус сборки:

[![tag](https://img.shields.io/github/v/tag/mambaru/prefixdbd.svg?sort=semver)](https://github.com/mambaru/prefixdbd/tree/master)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/master/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/master)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/pre-release/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/master)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/devel/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/devel)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/wip-devel/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/wip-devel)
[![Coverage Report](https://gitlab.mamba.ru/cpp/prefixdbd/badges/pre-release/coverage.svg)](http://github.lan/cpp/prefixdbd/commits/master)
[![Coverage Report](https://gitlab.mamba.ru/cpp/wfc_prefixdb/badges/pre-release/coverage.svg)](http://github.lan/cpp/wfc_prefixdb/commits/master)

# Сборка на repobuild3

Здесь уже все установлено 

```bash
BOOST_ROOT=/usr/monamour/boost/ ROCKSDB_ROOT=/usr/monamour/rocksdb/ make static ARGS=-j4
```

# Сборка на другой машине 

Зависимости для PrefixDB
* boost-1.71 скорее всего в репах еще нет, нужно установить в ручную

Зависимости для RocksDB и PrefixDB
* Install gflags. First, try: sudo apt-get install libgflags-dev
* If this doesn't work and you're using Ubuntu, here's a nice tutorial:
* (http://askubuntu.com/questions/312173/installing-gflags-12-04)
* Install snappy. This is usually as easy as:
* sudo apt-get install libsnappy-dev.
* Install zlib. Try: sudo apt-get install zlib1g-dev.
* Install bzip2: sudo apt-get install libbz2-dev.
* Install lz4: sudo apt-get install liblz4-dev.
* Install zstandard: sudo apt-get install libzstd-dev.

Сборка RocksDB:
```bash
USE_RTTI=1 make shared_lib
USE_RTTI=1 make static_lib
sudo INSTALL_PATH=/usr/monamour/rocksdb make install-shared
sudo INSTALL_PATH=/usr/monamour/rocksdb make install-static
sudo mkdir -p /usr/monamour/rocksdb/db
sudo cp ./db/*.h /usr/monamour/rocksdb/db
```

https://gitlab.mamba.ru/cpp/rocksdb/-/blob/master/INSTALL.md

Сборка PrefixDB:
```bash
BOOST_ROOT=/path/to/boost/ ROCKSDB_ROOT=/path/to/rocksdb/ make static ARGS=-j4
```
