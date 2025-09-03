#!/bin/bash

# Script pour créer les dossiers nécessaires aux volumes bind
echo "Création des dossiers pour les volumes bind..."

if [ -f "./srcs/.env" ]; then
  export $(grep -v '^#' ./srcs/.env | xargs)
fi

TARGET_BASE_DIR="${DATA_PATH}"
if [ -z "${TARGET_BASE_DIR}" ]; then
  echo "Erreur: DATA_PATH n'est pas défini (srcs/.env)." >&2
  exit 1
fi

mkdir -p "${TARGET_BASE_DIR}/mariadb" "${TARGET_BASE_DIR}/wordpress"
chmod 755 "${TARGET_BASE_DIR}/mariadb" "${TARGET_BASE_DIR}/wordpress"

echo "Dossiers créés avec succès dans ${TARGET_BASE_DIR} !"
