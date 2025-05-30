NAME    = webserv

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98
CPPFLAGS= -Iinc

SRC_DIR = src
INC_DIR = inc

SRCS    = Config.cpp \
		Connection.cpp \
		Location.cpp \
		Request.cpp \
		Response.cpp \
		Server.cpp \
		ServerManager.cpp


OBJS    = $(SRCS:.cpp=.o)

DEPS    = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re