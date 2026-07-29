#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <string>

class ConnectorFactory;
class Transformation;
class RunCheckpoint;

class Pipeline {
protected:
    ConnectorFactory* factory;
    std::vector<Transformation*> steps;
    int stage;
    std::vector<std::string> records;

    void connect();
    virtual void extract() = 0;
    void transform();
    virtual void load() = 0;

public:
    Pipeline(ConnectorFactory* factory);
    void run();
    void addStep(Transformation* step);
    RunCheckpoint* createCheckpoint();
    void restore(RunCheckpoint* cp);
    virtual ~Pipeline();
};

#endif
