FROM alpine:latest

RUN apk update && apk add socat build-base

RUN addgroup -S ctf && adduser -S -G ctf ctf
RUN mkdir -p /home/ctf

COPY --chown=ctf challenge/main.c /home/ctf
COPY --chown=ctf source/ /home/ctf

WORKDIR /home/ctf

RUN make
RUN rm Makefile

USER ctf

EXPOSE 1337

CMD ["socat", "-T", "15", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:/home/ctf/leak_or_treat"]
