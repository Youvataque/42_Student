#!/bin/bash
set -e

DATADIR=/var/lib/mysql
mkdir -p "$DATADIR"
chown -R mysql:mysql "$DATADIR"

# 1) Initialisation du datadir si nécessaire (création des tables système)
if [ ! -d "$DATADIR/mysql" ]; then
  echo "[mariadb] init datadir"
  mariadb-install-db --user=mysql --datadir="$DATADIR" >/dev/null
fi

# 2) Démarrer en arrière-plan le serveur pour configurer comptes/DB
mysqld_safe --datadir="$DATADIR" &
for i in {1..60}; do
  mariadb-admin ping --silent && break
  sleep 1
done

# 3) Sécuriser root + créer DB/utilisateur applicatif (idempotent)
MYSQL_ROOT_PASSWORD=$(cat ${MYSQL_ROOT_PASSWORD_FILE})
MYSQL_PASSWORD=$(cat ${MYSQL_PASSWORD_FILE})

mysql -uroot -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';" || true
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
mysql -uroot -p"${MYSQL_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%'; FLUSH PRIVILEGES;"

# 4) Stop propre, puis handover au CMD (mysqld_safe en PID 1)
mysqladmin -uroot -p"${MYSQL_ROOT_PASSWORD}" shutdown
exec "$@"