FROM python:3.11-slim

RUN groupadd -r ctf && useradd -r -g ctf ctf
RUN mkdir -p /home/ctf

COPY --chown=ctf challenge/ /home/ctf/

WORKDIR /home/ctf

RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/calculator.py

USER ctf

CMD ["python","calculator.py"]
