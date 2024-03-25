SERVER = server
B_SERVER = b_server
CLIENT = client
B_CLIENT = b_client
LIBFT = cd libft && make && make bonus
LIB = libft/libft.a

S_SOURCES = server.c\

C_SOURCES = client.c\

BS_SOURCES = server_bonus.c\

BC_SOURCES = client_bonus.c\

S_OBJECTS = $(S_SOURCES:.c=.o)

C_OBJECTS = $(C_SOURCES:.c=.o)

BS_OBJECTS = $(BS_SOURCES:.c=.o)

BC_OBJECTS = $(BC_SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

	

all:  $(SERVER) $(CLIENT) 


$(SERVER): $(S_OBJECTS) 
	@$(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJECTS) $(LIB) -o $(SERVER)

$(CLIENT): $(C_OBJECTS)	
	$(CC) $(CFLAGS) $(C_OBJECTS) $(LIB) -o $(CLIENT)

$(B_SERVER): $(BS_OBJECTS) 
	@$(LIBFT)
	$(CC) $(CFLAGS) $(BS_OBJECTS) $(LIB) -o $(B_SERVER)

$(B_CLIENT): $(BC_OBJECTS)
	$(CC) $(CFLAGS) $(BC_OBJECTS) $(LIB) -o $(B_CLIENT)


bonus: $(B_SERVER) $(B_CLIENT)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(C_OBJECTS)
	@cd libft && make clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(B_SERVER) $(B_CLIENT)
	@cd libft && make fclean

re: fclean all