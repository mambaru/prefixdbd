# Статус сборки 

Сборка мастера осуществляется автоматическиa, поэтому сразу переходим на [деплой](deploy.md). Текущий статус сборки:

[![tag](https://img.shields.io/github/v/tag/mambaru/prefixdbd.svg?sort=semver)](https://github.com/mambaru/prefixdbd/tree/master)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/master/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/master)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/pre-release/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/master)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/devel/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/devel)
[![pipeline status](https://gitlab.mamba.ru/cpp/prefixdbd/badges/wip-devel/pipeline.svg)](http://github.lan/cpp/prefixdbd/commits/wip-devel)
[![Coverage Report](https://gitlab.mamba.ru/cpp/prefixdbd/badges/pre-release/coverage.svg)](http://github.lan/cpp/prefixdbd/commits/master)
[![Coverage Report](https://gitlab.mamba.ru/cpp/wfc_prefixdb/badges/pre-release/coverage.svg)](http://github.lan/cpp/wfc_prefixdb/commits/master)

# Сборка на repobuild3 и repobuild4

Здесь уже все установлено (по умолчанию все в статику собирается)

```bash
BOOST_ROOT=/usr/monamour/boost/ ROCKSDB_ROOT=/usr/monamour/rocksdb/ make release ARGS=-j4
```

Бинарь в `./build/bin/prefixdbd`

# Сборка на другой машине 

Долгая сборка с подгрузкой и компиляцией boost и rocksdb

```bash
make release
```

# Сборка RocksDB (минимум 1.76, но лучше последняя)
```bash
wget https://boostorg.jfrog.io/artifactory/main/release/1.81.0/source/boost_1_81_0.tar.gz
tar -xvf boost_1_81_0.tar.gz
cd boost_1_81_0/
./bootstrap.sh --prefix=/usr/monamour/boost
sudo ./b2 --prefix=/usr/monamour/boost variant=release link=static threading=multi runtime-link=static install
```

# Сборка RocksDB (только если автоматическая не сработала или не устраивает)

Зависимости для RocksDB и PrefixDB
* **Install gflags**. First, try: sudo apt-get install libgflags-dev
* If this doesn't work and you're using Ubuntu, here's a nice tutorial:
* (http://askubuntu.com/questions/312173/installing-gflags-12-04)
* **Install snappy**. This is usually as easy as: sudo apt-get install libsnappy-dev.
* Install zlib. Try: sudo apt-get install zlib1g-dev.
* Install bzip2: sudo apt-get install libbz2-dev.
* Install lz4: sudo apt-get install liblz4-dev.
* Install zstandard: sudo apt-get install libzstd-dev.

Без библиотек архиваторов сборка rocksdb произойдет успешно, но без их поддержки, соответственно существующие базы которые используют сжатие (тип указывается в ini) работать не будут. У нас используется только snappy, поэтому его устанавливать обязательно (проверка осуществляеться в проекте ptrfixdb).   

Сборка RocksDB:
```bash
USE_RTTI=1 make static_lib
sudo PREFIX=/usr/monamour/rocksdb make install-static
sudo mkdir -p /usr/monamour/rocksdb/db
sudo cp ./db/*.h /usr/monamour/rocksdb/db
```

https://gitlab.mamba.ru/cpp/rocksdb/-/blob/master/INSTALL.md

