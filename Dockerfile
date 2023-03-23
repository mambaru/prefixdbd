FROM debian
ENV LD_LIBRARY_PATH=/usr/local/lib
RUN apt update; apt install  -y libsnappy1v5 libgflags2.2; rm -rf /var/lib/{apt,dpkg,cache,log}/
COPY binaries/prefixdbd  /usr/local/bin/	
COPY libs/lib/ /usr/local/lib
RUN groupadd -g 80 www \
    && useradd -u 30 --shell /sbin/nologin --group www wwwrun;
WORKDIR /usr/monamour/prefixdb/
USER wwwrun
