CC = gcc
CFLAGS = -Wall -Wextra
SRC_DIR = src
BUILD_DIR = build
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_BIN = $(BUILD_DIR)/client
SERVER_BIN = $(BUILD_DIR)/server

all: $(CLIENT_BIN) $(SERVER_BIN)

$(CLIENT_BIN): $(CLIENT_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(SERVER_BIN): $(SERVER_SRC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
