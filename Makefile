##
## Makefile en  /home/margaritu/socket
##-------------------------------
## Non scholae, sed vitae discere.
##------------------------------- 
## Login   <mininoxeixo28@gmail.com>
## Iniciado   lun 8 ago 2022 11∶08∶52
## Finalizado lun 15 ago 2022 18∶18∶53  
## 
##

SRC	= src/main.c \
	  src/utilidad/Intercambio_Msg_Serv_Cli.c \
    
OBJ	= $(SRC:.c=.o)

NAME	= Servidor_Consola

RM	= rm -f

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -pedantic-errors
CFLAGS	+= -I./include

all: $(NAME) ## multples nombres

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all