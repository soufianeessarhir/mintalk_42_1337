SERVER = server
CLIENT = client
LIBFT = cd libft && make
LIB = libft/libft.a

S_SOURCES = server.c\

C_SOURCES = client.c\


S_OBJECTS = $(S_SOURCES:.c=.o)
C_OBJECTS = $(C_SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

comp_start:
	@$(LIBFT)
	@make all

all:  $(SERVER) $(CLIENT) 


$(SERVER): $(S_OBJECTS) 
	$(CC) $(CFLAGS) $(S_OBJECTS) $(LIB) -o $(SERVER)

$(CLIENT): $(C_OBJECTS) 
	$(CC) $(CFLAGS) $(C_OBJECTS) $(LIB) -o $(CLIENT)
#bonus:$(CLIENT)


%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(C_OBJECTS)
	@cd libft && make clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@cd libft && make fclean

re: fclean comp_start