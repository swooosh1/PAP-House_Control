BIN=get
OBJECTS = get.o
LIBS = -lm -lserialPort -lboost_system -lboost_thread-mt -lserialPort

INC_PATH = ../serialPort
LIB_PATH = ../serialPort
BIN_PATH = /opt/lampp/cgi-bin

TARGET=$(BIN_PATH)/$(BIN)

CFLAGS = -Wall  -I$(INC_PATH)
CC = g++ $(CFLAGS) 

RM = rm -rf

.PHONY: all
all: clean $(TARGET) cleanobj
	
$(TARGET): $(OBJECTS)
	#@-sh ./CreateIncludeLinks.sh
	@echo "[;;43m** Linking $@ [0;;m"
	@-$(CC)  -L$(LIB_PATH) -o $@ $^ $(LIBS);\
	if [ $$? -eq 0 ]; then \
		echo "[;;42m** Success[0;;m";\
	else \
		echo "[;;41m** Error[0;;m";\
	fi 
	@echo

%.o: %.cpp 
	@echo "[;;43m** Compiling $@[0;;m"
	@-$(CC) -c $< -o $@ -g;\
	if [ $$? -eq 0 ]; then \
		echo "[;;42m** Success[0;;m";\
	else \
		echo "[;;41m** Error[0;;m";\
	fi 
	@echo

clean:
	@echo "[;;43m** Cleaning $(BIN) files[0;;m"
	@$(RM) $(OBJECTS) $(TARGET)
	@echo "[;;42m** Done[0;;m";
	@echo
cleanobj:
	@$(RM) $(OBJECTS)



