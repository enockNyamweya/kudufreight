#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <vector>

class RunCheckpoint;

class CheckpointManager {
private:
    std::vector<RunCheckpoint*> history;
public:
    void save(RunCheckpoint* cp);
    RunCheckpoint* undo();
    ~CheckpointManager();
};

#endif
