
LDLIBS = -lSDL2 -lm

CXXFLAGS = -g -Wall
srcdirs = src src/core src/core/math src/system src/world
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
bin/core/math/%.o: src/core/math/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
bin/system/%.o: src/system/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
bin/world/%.o: src/world/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: mkdirs
mkdirs:
	mkdir $(objdirs)

.PHONY: clean
clean:
	rm -rf bin
