FROM debian
COPY binaries/prefixdbd  /usr/local/bin/	
RUN groupadd -g 80 www \
    && useradd -u 30 --shell /sbin/nologin --group www wwwrun;
WORKDIR /usr/monamour/prefixdb/
USER wwwrun
