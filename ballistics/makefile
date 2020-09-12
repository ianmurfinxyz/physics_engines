
LDLIBS = -lSDL2 -lm

CXXFLAGS = -g -Wall
srcdirs = src src/core src/system
objdirs = $(subst src,bin,$(srcdirs))

# Grab all source and header files in all $(dirs)
# see: https://www.gnu.org/software/make/manual/html_node/Foreach-Function.html
cxxsrc = $(foreach dir,$(srcdirs),$(wildcard $(dir)/*.cpp))
includes = $(foreach dir,$(srcdirs),$(wildcard $(dir)/*.h))

# compose the names of all .o files to create
objs = $(cxxsrc:.cpp=.o)
objs := $(subst src/,bin/,$(objs))

# name of executable output
main = engine

$(main): $(objs) $(includes)
	$(CXX) $(CXXFLAGS) -o bin/$@ $(objs) $(LDLIBS)

# define a pattern rule for all $(srcdirs) -> is there a better way?
bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
bin/core/%.o: src/core/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
bin/system/%.o: src/system/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: mkdirs
mkdirs:
	echo "making obj dirs: $(objdirs)"
	mkdir $(objdirs)

.PHONY: clean
clean:
	rm -f $(objs) bin/$(main)
	rmdir bin

#.PHONY: install
#install: $(main)
#	mkdir -p $(DESTDIR)$(PREFIX)/bin
#	cp bin/$(main) $(DESTDIR)$(PREFIX)/bin/$(main)
#	mkdir -p $(DESTDIR)$(PREFIX)/man/man1
#	cp man/$(main).1 $(DESTDIR)$(PREFIX)/man/man1/$(main).1
#
#.PHONY: uninstall
#uninstall:
#	rm -f $(DESTDIR)$(PREFIX)/bin/$(main)
#	rm -f $(DESTDIR)$(PREFIX)/bin/$(main_run)
#	rm -f $(DESTDIR)$(PREFIX)/man/man1/$(main).1
#	rm -f $(DESTDIR)$(PREFIX)/man/man1/$(main_run).1
	
