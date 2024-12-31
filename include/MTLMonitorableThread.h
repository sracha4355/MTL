#ifndef MTLMONITORABLETHREAD_H
#define MTLMONITORABLETHREAD_H

#pragma once

#include "MTLThread.h"
#include "MTLRunnable.h"
#include "MTLSharedMemory.h"
#include <memory>

/**
 * Workflow: subclass MTL monitorable Thread with a polling function
 * subclass a MTLMontiorableRunnable where you need to pass a pointer to a shared memory 
 */
namespace MTL
{
    class MTLMonitorableRunnable: public MTLRunnable 
    {
        public:
            MTLMonitorableRunnable(std::shared_ptr<MTLSharedMemory>);
            virtual ~MTLMonitorableRunnable() = default;
            std::shared_ptr<MTLSharedMemory> shareSharedMemory();
        private: 
            bool m_memory_shared;
            std::shared_ptr<MTLSharedMemory> m_objectStorage;
    };

    class MTLMonitorableThread: public MTLThread 
    {
        public:
            MTLMonitorableThread(MTLMonitorableRunnable &runnable);
            virtual ~MTLMonitorableThread() = default;
            virtual void poll() = 0;
        private:
            std::shared_ptr<MTLSharedMemory> m_sharedMemory;
            MTLMonitorableRunnable &m_runnable;
    };  
}

#endif