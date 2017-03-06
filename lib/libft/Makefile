# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 15:04:37 by vchaillo          #+#    #+#              #
#    Updated: 2017/02/23 04:34:01 by vchaillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -Rf

# Colors
GREY = \033[30;1m
RED = \033[31;1m
GREEN =	\033[32;1m
YELLOW = \033[33;1m
BLUE = \033[34;1m
WHITE = \033[37;1m
END_COLOR =	\033[0m

# Directories
SRCDIR = srcs/
OBJDIR = obj/
OBJSUBDIR = obj/string obj/memory obj/print obj/convert obj/list

# Sources files
SRC_STRING = \
		string/ft_strlen.c\
		string/ft_strcpy.c\
		string/ft_strncpy.c\
		string/ft_strcat.c\
		string/ft_strncat.c\
		string/ft_strcmp.c\
		string/ft_strncmp.c\
		string/ft_strnstr.c\
		string/ft_strchr.c\
		string/ft_strrchr.c\
		string/ft_strclr.c\
		string/ft_strdup.c\
		string/ft_strnew.c\
		string/ft_strdel.c\
		string/ft_strequ.c\
		string/ft_strnequ.c\
		string/ft_strsub.c\
		string/ft_strjoin.c\
		string/ft_strtrim.c\
		string/ft_striter.c\
		string/ft_striteri.c\
		string/ft_strmap.c\
		string/ft_strmapi.c\
		string/ft_strlcat.c\
		string/ft_strsplit.c\
		string/ft_strstr.c\
		string/ft_isalpha.c\
		string/ft_isdigit.c\
		string/ft_isalnum.c\
		string/ft_isascii.c\
		string/ft_isprint.c\

SRC_MEMORY = \
		memory/ft_memset.c\
		memory/ft_bzero.c\
		memory/ft_memcpy.c\
		memory/ft_memccpy.c\
		memory/ft_memchr.c\
		memory/ft_memmove.c\
		memory/ft_memcmp.c\
		memory/ft_memalloc.c\
		memory/ft_memdel.c\

SRC_PRINT = \
		print/ft_putchar.c\
		print/ft_putstr.c\
		print/ft_putendl.c\
		print/ft_putnbr.c\
		print/ft_putfloat2.c\
		print/ft_putendl_color.c\
		print/ft_putstr_color.c\
		print/ft_putnbr_color.c\
		print/ft_putchar_fd.c\
		print/ft_putstr_fd.c\
		print/ft_putendl_fd.c\
		print/ft_putnbr_fd.c\

SRC_CONVERT = \
		convert/ft_tolower.c\
		convert/ft_toupper.c\
		convert/ft_atoi.c\
		convert/ft_itoa.c\

SRC_LIST = \
		list/ft_lstnew.c\
		list/ft_lstdelone.c\
		list/ft_lstdel.c\
		list/ft_lstadd.c\
		list/ft_lstiter.c\
		list/ft_lstmap.c\

SRC_GNL = \
		get_next_line.c\

SRC = $(SRC_STRING) $(SRC_MEMORY) $(SRC_PRINT) $(SRC_CONVERT) $(SRC_LIST) $(SRC_GNL)

# Objects files
OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

INC = -I includes

# Rules
all: $(NAME)

$(NAME): obj $(OBJ)
		@echo "==========================="
		@printf "$(WHITE)Creating $(NAME)... $(END_COLOR)"
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$(GREEN)Done √$(END_COLOR)"
		@echo "==========================="

DEPS := $(OBJ:.o=.d)
-include $(DEPS)
$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) $(INC) -MD -o $@ -c $<
		@echo "[$(GREEN)√$(END_COLOR)]" $(subst obj,src,$(subst .o,.c,$@))

obj:
		@mkdir -p $(OBJDIR)
		@mkdir -p $(OBJSUBDIR)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJDIR)
		@echo "$(BLUE)libft$(GREY) - Cleaning object files$(END_COLOR)"

fclean:	clean
		@echo "$(BLUE)libft$(GREY) - Cleaning library$(END_COLOR)"
		@$(RM) $(NAME)

norm:
		@echo "$(BLUE)Norminette...$(END_COLOR)"
		@norminette includes/*.h srcs/**/*.c

re: fclean all

.PHONY: all obj clean fclean norm re
