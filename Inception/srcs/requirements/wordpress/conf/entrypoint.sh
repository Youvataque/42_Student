#!/bin/sh
set -eu

: "${MYSQL_HOST:?missing}"
: "${MYSQL_DATABASE:?missing}"
: "${MYSQL_USER:?missing}"
: "${MYSQL_PASSWORD_FILE:?missing}"
: "${WP_ROOT_USER:?missing}"
: "${WP_ROOT_PASSWORD:?missing}"
: "${WP_ROOT_EMAIL:?missing}"
: "${DOMAIN_NAME:?missing}"

WP_PATH=/var/www/html
MYSQL_PASSWORD=$(cat ${MYSQL_PASSWORD_FILE})

# ici les logs feront office de commentaires
echo "[wp] waiting for mariadb..."
until mysql -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" "$MYSQL_DATABASE" -e "SELECT 1;" >/dev/null 2>&1; do
  echo "[wp] waiting for mariadb connection..."
  sleep 2
done
echo "[wp] mariadb is up"

if [ ! -f "$WP_PATH/wp-config.php" ]; then
  echo "[wp] downloading WordPress..."
  wp core download --allow-root --path="$WP_PATH"
  
  echo "[wp] creating wp-config.php..."
  wp config create --allow-root --path="$WP_PATH" \
    --dbname="$MYSQL_DATABASE" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --dbhost="$MYSQL_HOST" --skip-check
  
  echo "[wp] installing WordPress..."
  wp core install --allow-root --path="$WP_PATH" \
    --url="https://${DOMAIN_NAME}" --title="Inception" \
    --admin_user="$WP_ROOT_USER" --admin_password="$WP_ROOT_PASSWORD" --admin_email="$WP_ROOT_EMAIL" --skip-email
fi

echo "[wp] starting php-fpm..."
exec "$@"