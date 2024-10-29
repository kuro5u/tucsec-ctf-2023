FROM python:3.10-alpine
WORKDIR /app
RUN apk add --update \
    curl \
    && rm -rf /var/cache/apk/*
COPY source/ .
RUN mv flag /
RUN pip install -r requirements.txt
EXPOSE 1337
CMD ["python", "app.py"]
