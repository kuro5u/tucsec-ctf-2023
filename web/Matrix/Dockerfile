FROM python:3.10-alpine
WORKDIR /app
RUN apk add --update \
    curl \
    && rm -rf /var/cache/apk/*
COPY . .
COPY flag /
RUN pip install -r requirements.txt
EXPOSE 5000
CMD ["python", "app.py"]