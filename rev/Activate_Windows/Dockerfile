FROM alpine:latest

RUN apk update && apk add socat build-base

RUN addgroup -S ctf && adduser -S -G ctf ctf
RUN mkdir -p /home/ctf

COPY --chown=ctf source/ /home/ctf

WORKDIR /home/ctf

RUN make
RUN rm Makefile main.c

USER ctf

EXPOSE 1337

CMD ["socat", "-T", "15", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:/home/ctf/activate_windows"]
