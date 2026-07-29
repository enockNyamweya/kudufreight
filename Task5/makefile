CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCS = main.cpp \
       ../Task1/Connector.cpp ../Task1/CsvConnector.cpp ../Task1/PostgresConnector.cpp ../Task1/RestApiConnector.cpp \
       ../Task1/ConnectorFactory.cpp ../Task1/CsvFactory.cpp ../Task1/PostgresFactory.cpp ../Task1/RestApiFactory.cpp \
       ../Task2/Transformation.cpp ../Task2/DeduplicateStep.cpp ../Task2/AggregateByRegionStep.cpp ../Task2/TransformationRegistry.cpp \
       ../Task3/Pipeline.cpp ../Task3/BatchPipeline.cpp ../Task3/StreamingPipeline.cpp \
       ../Task4/RunCheckpoint.cpp ../Task4/CheckpointManager.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = engine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
