NAME	= fractol
SRCS	= main.c

OBJS	= $(SRCS:.c=.o)
HEADERS	= fractol.h
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -O2

MINILIBX_URL := https://cdn.intra.42.fr/document/document/27135/minilibx-linux.tgz
MINILIBX_TAR_GZ := minilibx-linux.tgz
MINILIBX_DIR := ./minilibx-linux
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR)
LIBS = -lm -lmlx

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx_linux -O3 -c $< -o $@

$(MINILIBX_TAR_GZ):
	curl -O $(MINILIBX_URL)

$(MINILIBX): $(MINILIBX_TAR_GZ)
	tar xvzf $(MINILIBX_TAR_GZ)
	make -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	make -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MINILIBX_DIR)
	rm $(MINILIBX_TAR_GZ)

re: fclean all

.PHONY: all clean fclean re
