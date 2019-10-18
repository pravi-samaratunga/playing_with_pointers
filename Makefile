
PROJECTS := 00_basic_pointers 01_doubly_linked_list 02_new_keyword

CXX := gcc

EXEC_DIR = bin/
SRC_DIR = src/
INCL_HEADERS = 

CXXFLAGS := -std=c++11
LDFLAGS := -lstdc++

TARGETS := $(foreach x, $(PROJECTS), $(EXEC_DIR)$(x).o)

#all: $(TARGETS)

00_basic_pointers:
	@mkdir -p $(EXEC_DIR)
	@$(CXX) $(CXXFLAGS) -DY_STAR_ANS=$(shell echo "\061\060") -DZ_VAL_ANS=$(shell echo "\\\"\\\"") -DCHAR_STAR_Y_ANS=$(shell echo "\\\"\136\165\055\\\"") -DX_VAL_ANS=2979166 -o $(EXEC_DIR)$@.o $(SRC_DIR)$@.cpp $(LDFLAGS)
	@$(EXEC_DIR)$@.o $(shell echo "$(PROJECTS)")

01_doubly_linked_list:
	@mkdir -p $(EXEC_DIR)
	$(CXX) $(CXXFLAGS) -DDLL_P_VAL_ANS=$(shell echo "\\\"\122\145\144\\\"") -DINITIAL_POINTS="(QUESTION_1_RESPONSE == $(shell echo "\064*\064/\070")) + (QUESTION_2_RESPONSE == $(shell echo "\063*\061-\061")) + (QUESTION_3_RESPONSE == $(shell echo "\066-\063"))" -o $(EXEC_DIR)$@.o $(SRC_DIR)$@.cpp $(LDFLAGS)
	@$(EXEC_DIR)$@.o $(shell echo "$(PROJECTS)");

#$(TARGETS) : $(EXEC_DIR)%.o : $(SRC_DIR)%.cpp
#	mkdir -p $(EXEC_DIR)
#	$(CXX) $(CXXFLAGS) -o $(EXEC_DIR)$@ $< $(LDFLAGS) 

clean:
	$(RM) $(EXEC_DIR) -r
