#include "RunCheckpoint.h"

RunCheckpoint::RunCheckpoint(int stage, std::vector<std::string> records)
    : stage(stage), records(records) {}

int RunCheckpoint::getStage() {
    return stage;
}

std::vector<std::string> RunCheckpoint::getRecords() {
    return records;
}
