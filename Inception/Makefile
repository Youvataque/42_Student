COMPOSE = ./load-env.sh

.PHONY: up down build start stop logs ps clean fclean re

up:
	./setup-volumes.sh
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down

build:
	$(COMPOSE) build

start:
	$(COMPOSE) start

stop:
	$(COMPOSE) stop

logs:
	$(COMPOSE) logs -f

ps:
	$(COMPOSE) ps

clean:
	$(COMPOSE) down -v

fclean: clean
	docker system prune -af || true
	docker volume prune -f || true

re: fclean up
