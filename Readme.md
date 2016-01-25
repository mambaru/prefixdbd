Компиляция на cdaeamonbuild(10.5.13.222):
```bash
git clone git@github.lan:cpp/prefixdbd.git
cd prefixdbd
git checkout devel-0.6
git submodule update --init --recursive 

scl enable devtoolset-2 bash
PORTABLE=1
mkdir build
cd build
cmake ..
make
cd ./Release/
```