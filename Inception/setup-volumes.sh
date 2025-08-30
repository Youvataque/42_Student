#!/bin/bash

# Script pour créer les dossiers nécessaires aux volumes bind
echo "Création des dossiers pour les volumes bind..."

# Créer les dossiers tools
mkdir -p srcs/requirements/mariadb/tools
mkdir -p srcs/requirements/wordpress/tools

# S'assurer que les dossiers ont les bonnes permissions
chmod 755 srcs/requirements/mariadb/tools
chmod 755 srcs/requirements/wordpress/tools

echo "Dossiers créés avec succès !"
