SERVER = server
CLIENT = client
S_SOURCES = server.c\

C_SOURCES = 

S_OBJECTS = $(S_SOURCES:.c=.o)
C_OBJECTS = $(C_SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

all: $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJECTS) 
	$(CC) $(CFLAGS) $(S_OBJECTS) -o $(SERVER)

$(CLIENT): $(CH_OBJECTS) 
	$(CC) $(CFLAGS) $(CH_OBJECTS) -o $(CLIENT)
#bonus:$(CLIENT)


%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(CH_OBJECTS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all