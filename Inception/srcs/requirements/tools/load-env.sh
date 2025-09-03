#!/bin/bash

if [ -f "./secrets/credentials.txt" ]; then
    export $(grep -v '^#' ./secrets/credentials.txt | xargs)
fi

if [ -f "./srcs/.env" ]; then
    export $(grep -v '^#' ./srcs/.env | xargs)
fi

# Lancer docker-compose avec toutes les variables chargées
docker-compose -f ./srcs/docker-compose.yml "$@"
