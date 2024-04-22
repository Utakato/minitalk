
SRV_SOURCES = server.c
CLIENT_SOURCES = client.c

CC = cc

CFLAGS = -fsanitize=address -Wall -Wextra -Werror

NAME = minitalk

all: $(NAME)

$(NAME): clean server client
	@echo "Done"

re : fclean all

client: $(CLIENT_SOURCES)
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) $(CLIENT_SOURCES) -o client

server: $(SRV_SOURCES)
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) $(SRV_SOURCES) -o server

run: $(NAME)
	@echo "Running... \n"
	@./a.out

clean: 
	@echo "Cleaning..."
	@rm server	
	@rm client

fclean: clean
	@echo "Full cleaning..."
	rm -f $(NAME)