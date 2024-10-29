FROM python:3.10-alpine
WORKDIR /app
COPY challenge/ .
COPY source/flag /
RUN pip install -r requirements.txt
EXPOSE 5000
CMD ["python", "app.py"]
