FROM debian
ENV LD_LIBRARY_PATH=/usr/local/lib
RUN apt update; apt install  -y libsnappy1v5; rm -rf /var/lib/{apt,dpkg,cache,log}/
COPY binaries/prefixdbd  /usr/local/bin/	
COPY libs/lib/ /usr/local/lib


