#ifndef STREAMINGPIPELINE_H
#define STREAMINGPIPELINE_H

#include "Pipeline.h"

class StreamingPipeline : public Pipeline {
protected:
    void extract() override;
    void load() override;
public:
    StreamingPipeline(ConnectorFactory* factory);
};

#endif
