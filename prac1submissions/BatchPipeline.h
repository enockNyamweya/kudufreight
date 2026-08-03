#ifndef BATCHPIPELINE_H
#define BATCHPIPELINE_H

#include "Pipeline.h"

class BatchPipeline : public Pipeline {
protected:
    void extract() override;
    void load() override;
public:
    BatchPipeline(ConnectorFactory* factory);
};

#endif
