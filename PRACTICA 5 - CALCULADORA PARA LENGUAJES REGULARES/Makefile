# CYA1819 - P5

TARGET = regCalc

SRC = src
INC = include
BIN = bin

CXX = g++ -g
CFLAGS = -std=c++11 -I$(INC)
RM = rm -f
#FLAGS = -o

SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(patsubst %, $(BIN)/% ,$(notdir $(SOURCE:.cpp=.o)))

######## Compilador
$(BIN)/$(TARGET) : $(OBJECT)
				$(CXX) -o $@ $^ #$(FLAGS)
# -c "Compile but not link"
$(BIN)/%.o : $(SRC)/%.cpp | bin
				$(CXX) $(CFLAGS) -c $< -o $@
# for creating bin directory if it doesn't exist
bin:
	mkdir -p $@

####### Alias for cleaning and runing
.PHONY: run clean

run : 
	$(BIN)/$(TARGET)

clean:
	rm -f $(OBJECT) $(BIN)/$(TARGET)
