#include "CheckpointManager.h"
#include "RunCheckpoint.h"

CheckpointManager::~CheckpointManager() {
    history.clear();
}

void CheckpointManager::save(RunCheckpoint* cp) {
    if (cp != nullptr) {
        history.push_back(cp);
    }
}

RunCheckpoint* CheckpointManager::undo() {
    if (history.empty()) {
        return nullptr;
    }
    RunCheckpoint* last = history.back();
    history.pop_back();
    return last;
}
