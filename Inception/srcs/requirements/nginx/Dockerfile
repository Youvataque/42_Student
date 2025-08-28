FROM debian:bookworm

ARG DOMAIN_NAME
RUN apt-get update -y && apt-get install -y nginx openssl curl && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=${DOMAIN_NAME}/UID=login"

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
RUN mkdir -p /var/www/html && chmod 755 /var/www/html && chown -R www-data:www-data /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]