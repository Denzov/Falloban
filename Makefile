
CONFIG ?= debug
PREFIX ?= ./install

BUILD_DIR := build/$(CONFIG)

.PHONY: debug profile release package clean run

configure: $(BUILD_DIR)/CMakeCache.txt

$(BUILD_DIR)/CMakeCache.txt:
	cmake --preset $(CONFIG)

build: configure
	cmake --build $(BUILD_DIR)

run: build
	./$(BUILD_DIR)/Falloban

package: build
	cd $(BUILD_DIR) && cpack

install: build
	cmake --install $(BUILD_DIR) --prefix "$(PREFIX)"

clean:
	rm -rf build