FROM php:8.2-alpine
WORKDIR /app
COPY source/ .
RUN mv flag /
CMD ["php", "-S", "0.0.0.0:80"]
EXPOSE 80
