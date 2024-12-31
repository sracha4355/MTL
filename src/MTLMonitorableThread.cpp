#include "MTLMonitorableThread.h"
namespace MTL
{

    MTLMonitorableThread::MTLMonitorableThread(MTLMonitorableRunnable &runnable) : m_runnable(runnable)
    {
        m_sharedMemory = runnable.shareSharedMemory();
    }
    
    MTLMonitorableRunnable::MTLMonitorableRunnable(std::shared_ptr<MTLSharedMemory> shared_memory): 
    m_objectStorage(shared_memory), m_memory_shared(false) 
    {
    }
    std::shared_ptr<MTLSharedMemory> MTLMonitorableRunnable::shareSharedMemory()
    {
        if (!m_memory_shared)
        {
            m_memory_shared = true;
            return m_objectStorage;
        }
        return nullptr;
    }
}