#ifndef CHECKPOINTMANAGER_H
#define CHECKPOINTMANAGER_H

#include <vector>

class RunCheckpoint;

class CheckpointManager {
private:
    std::vector<RunCheckpoint*> history;

public:
    CheckpointManager() = default;
    ~CheckpointManager();

    void save(RunCheckpoint* cp);
    RunCheckpoint* undo();
};

#endif
