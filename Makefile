# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 19:28:33 by alex              #+#    #+#              #
#    Updated: 2024/11/30 17:39:56 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ruta_del_archivo_que_quieres_leer
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILE_NAME = GNL
MAIN = test1args.c
RUTA_MAIN = /home/$(USER)/$(FILE_NAME)/GNL_test/1fd/$(MAIN)

SRCS = get_next_line.c get_next_line_utils.c \
		$(RUTA_MAIN) \
		
HEADERS = get_next_line.h

all: $(NAME)
	@echo " "
	@echo "+⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀ ⣀⣀⣤⣤⣤⣀⡀"
	@echo "+⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀"
	@echo "+⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆"
	@echo "+⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆"
	@echo "+⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆"
	@echo "+⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠸⣼⡿"
	@echo "+⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉"
	@echo "+⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇"
	@echo "+⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇"
	@echo "+⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇"
	@echo "+⠀⠀ ⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠇"
	@echo "+⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇"
	@echo "+⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃"
	@echo "    _    _     ____    _    ____  ____  ___ _     "
	@echo "   / \\  | |   / ___|  / \\  |  _ \\|  _ \\|_ _| |    "
	@echo "  / _ \\ | |  | |     / _ \\ | |_) | |_) || || |    "
	@echo " / ___ \\| |__| |___ / ___ \\|  _ <|  _ < | || |___ "
	@echo "/_/   \\_\\_____\\____/_/   \\_\\_| \\_\\_| \\_\\___|_____|"
	@echo " La carpeta predefinida es: $(FILE_NAME). Si quieres cambiarla pon el nombre de la carpeta que contiene al proyecto EJ: make FILE_NAME="nombre de tu carpeta" "
	@echo " El test predefinido es: $(MAIN). Si quire cambiarlo pon el nombre del archivo que contiene tu main  EJ: MAIN="el test que quieras usar" "
	
$(NAME): 
	$(CC) $(CFLAGS) -g -I ../$(FILE_NAME) $(SRCS) -o $(NAME)
	
clean:
	rm $(NAME)
