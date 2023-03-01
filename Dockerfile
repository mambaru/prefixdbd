FROM debian
RUN apt update; apt install  -y build-essential gcc cmake wget ssh git
RUN mkdir /var/build
COPY . /var/build
RUN ssh-keyscan gitlab.mamba.ru >> /root/.ssh/known_hosts
WORKDIR /var/build
RUN make release ARGS=-j{nproc --all}
