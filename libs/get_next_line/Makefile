# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 21:05:12 by ugolin-olle       #+#    #+#              #
#    Updated: 2023/09/27 21:04:30 by ugolin-olle      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR   = includes
SRCDIR   = srcs
OBJDIR   = objs

SRCS     = $(wildcard $(SRCDIR)/*.c)
OBJS     = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME     = libget_next_line.a
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
AR       = ar rcs

DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)get_next_line has been successfully compiled$(DEFCOLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling: $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)get_next_line object files cleaned!$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJDIR)
	@echo "$(CYAN)get_next_line executable has been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re
