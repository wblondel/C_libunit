# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wblondel <wblondel@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/04 02:31:10 by wblondel     #+#   ##    ##    #+#        #
#    Updated: 2017/12/04 03:01:37 by wblondel    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# Compiler configuration
#CC= gcc
CFLAGS= -Wall -Wextra -Werror

## Flags for the C preprocessor
CPPFLAGS= -I$(SRC_PATH) -I$(LIB) -I$(INC_PATH)

## Libraries path
LDFLAGS= -L$(LIB)

## Libraries to link into the library
LDLIBS= -lft

NAME=libunit.a


# Project related variables
SRC_PATH = src
INC_PATH = inc
OBJ_PATH = obj

SRC_NAME = suite.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft
HEADER = $(INC_PATH)/libunit.h

# Tracks malloc() and free()
ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif

# Entry point
all: $(NAME)

# Compiles libunit
$(NAME): $(LIB)/$(LIB).a $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# Compiles libft/libft.a
# It's a prerequisite to compile libunit
$(LIB)/$(LIB).a:
	$(MAKE) -C ./$(LIB)

# Creates obj/ directory
# It's a prerequisite to compile any OBJ
$(OBJ_PATH):
	mkdir $@

$(OBJ): | $(OBJ_PATH)

# Compiles all the src/ into obj/
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

ifeq ($(shell $(MAKE) --question -C ./$(LIB) ; echo $$?), 1)
.PHONY: $(LIB)/$(LIB).a
endif

.PHONY: clean
clean:
	$(MAKE) -C ./$(LIB) clean
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(MAKE) -C ./$(LIB) fclean
	$(RM) -r $(NAME) $(NAME).dSYM

re: fclean
	$(MAKE) all
