FROM python:3.11-slim

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf

COPY --chown=ctf source/ /home/ctf/

WORKDIR /home/ctf

RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/server.py

USER ctf

EXPOSE 1337

CMD ["python","server.py"]
