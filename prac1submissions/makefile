CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCS = main.cpp \
       Connector.cpp CsvConnector.cpp PostgresConnector.cpp RestApiConnector.cpp \
       ConnectorFactory.cpp CsvFactory.cpp PostgresFactory.cpp RestApiFactory.cpp \
       Transformation.cpp DeduplicateStep.cpp AggregateByRegionStep.cpp TransformationRegistry.cpp \
       Pipeline.cpp BatchPipeline.cpp StreamingPipeline.cpp \
       RunCheckpoint.cpp CheckpointManager.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = engine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

coverage: CXXFLAGS += --coverage
coverage: clean $(TARGET)
	./$(TARGET)
	gcov $(SRCS)

valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) *.gcno *.gcda *.gcov

.PHONY: all clean coverage valgrind
