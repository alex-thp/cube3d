CFLAGS = -Wall -Werror -Wextra
SANI_FLAGS = -g3 -fsanitize=address
NAME = Cub3D

SRC_FILE = cub3d.c sprite.c sprite_2.c screenshot.c cub3d_utils.c cub3d_utils_2.c\
cub3d_utils_3.c cub3d_utils_4.c cub3d_utils_5.c parse_doc.c parse_doc_2.c\
parse_doc_3.c parse_doc_4.c parse_doc_5.c parse_doc_6.c
GNL_FILE = get_next_line.c get_next_line_utils.c

LIB_PATH = libft/
LIB_FILE = ft_split.c \
ft_substr.c \
ft_calloc.c \
ft_bzero.c \
ft_strjoin.c \
ft_atoi.c \
ft_putstr_fd.c \
ft_putchar_fd.c \
ft_strchr.c \
ft_sdupfr.c \
ft_isdigit.c \
ft_strlen.c \
ft_memcpy.c \
ft_strdup.c

GNL_PATH = gnl/
INC= cub3d.h
SRC = ${SRC_FILE} ${addprefix ${GNL_PATH}, $(GNL_FILE)} ${addprefix ${LIB_PATH}, $(LIB_FILE)}
OBJS = ${SRC:%.c=%.o}
FRAMEWORK = -framework OpenGL -framework AppKit
LIBS = -lGLEW -lglfw -lGL
LIB = minilibx/

all: ${NAME}

$(NAME): ${INC} ${OBJS}
	@gcc $(CFLAGS) ${OBJS} -l mlx $(FRAMEWORK) -o Cub3D

%.o : %.c
	@gcc $(CFLAGS) -c -I include/ $< -o $@

clean:
	rm -f ${OBJS} ${BONUS}

fclean: clean
	rm -f ${NAME}

bonus :

re: fclean all
