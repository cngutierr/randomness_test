CLEANUP = rm -f
MKDIR = mkdir -p
TARGET_EXTENSION=.out

UNITY_ROOT=../Unity
C_COMPILER=gcc

CFLAGS = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror 
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -Wmissing-prototypes
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_FIXTURES

#TARGET_BASE1=all_tests
ALL_TESTS=all_tests

TARGET1 = $(ALL_TESTS)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/3rdparty/cephes.c\
  src/utils.c \
  src/rand_tests.c\
  unit_tests/test_utils.c \
  unit_tests/test_rand.c \
  unit_tests/test_runners/TestUtil_runner.c \
  unit_tests/test_runners/TestRand_runner.c \
  unit_tests/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=

all: clean default min_bit

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1) -lm
	./$(TARGET1) -v

clean:
	$(CLEANUP)

min_bit:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) -o min_bit src/3rdparty/cephes.c src/utils.c src/rand_tests.c src/min_bit.c -lm
