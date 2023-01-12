OBJDIR = obj
SRCDIR = src

# File names
NAME = raytrace.out
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Commands
CXX = g++
CXXFLAGS = -ansi -Wall -pedantic -std=c++11 -Wextra -g -MD
CPPFLAGS = -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
DEBUGFLAGS = -DMAP
RM = rm -f
ECHO = echo
LIBRAIRIES =

.PHONY: all clean fclean re run debug

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(NAME) $(LIBRAIRIES)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $@

debug:
	make re CXXFLAGS="$(CXXFLAGS) $(DEBUGFLAGS)"

clean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)

re: clean all

run: $(NAME)
	./$(NAME)

-include $(OBJS:.o=.d)