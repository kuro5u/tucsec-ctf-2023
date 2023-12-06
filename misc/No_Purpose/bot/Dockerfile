FROM python:3.11-slim

RUN pip install discord pwntools

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf

COPY --chown=ctf challenge/ /home/ctf/

WORKDIR /home/ctf

RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/main.py
RUN chmod 750 /home/ctf/bot.py

USER ctf

CMD ["python","main.py"]
