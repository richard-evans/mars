#--------------------------------------------------------------
#                 Makefile for input module
#--------------------------------------------------------------

# List module object filenames
input_objects=\
input.o

input_deps=\
src/input/input.hpp \
src/input/keywords.hpp \
src/input/parameters.hpp \
src/input/quantities.hpp \
src/input/tensors.hpp \
src/input/vectors.hpp

#$(input_objects) 

# Append module objects to global tree
OBJECTS+=$(addprefix obj/input/,$(input_objects))
#: $(input_deps)

# Custom rules
#obj/input/input.o : src/input/input.cpp $(input_deps)
#	$(GCC) -c -o $@ $(GCC_CFLAGS) $<
