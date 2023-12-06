FROM ubuntu:20.04

RUN apt-get update -y

RUN apt-get install -y socat build-essential

RUN apt-get clean && rm -rf /var/lib/apt/lists/*

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf

COPY --chown=ctf challenge/ /home/ctf/

WORKDIR /home/ctf
RUN make
RUN rm main.c Makefile

RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/mr_ropot
RUN chmod 440 /home/ctf/flag.txt

USER ctf

EXPOSE 1337

CMD ["socat", "-T", "15", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:/home/ctf/mr_ropot"]
