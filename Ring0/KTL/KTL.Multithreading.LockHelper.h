#pragma once


namespace ktl
{
    namespace Multithreading
    {
        template<typename _Lock>
        class lock_guard
        {
        public:
            explicit lock_guard(_Lock& aLock)
                : m_Lock(aLock)
            {
                m_Lock.lock();
            }

            ~lock_guard()
            {
                m_Lock.unlock();
            }

            lock_guard(const lock_guard&) = delete;
            lock_guard& operator=(const lock_guard&) = delete;

        protected:
            _Lock&  m_Lock;
        };

        template<typename _Lock>
        class shared_lock_guard
        {
        public:
            explicit shared_lock_guard(_Lock& aLock)
                : m_Lock(aLock)
            {
                m_Lock.lock_shared();
            }

            ~shared_lock_guard()
            {
                m_Lock.unlock_shared();
            }

            shared_lock_guard(const shared_lock_guard&) = delete;
            shared_lock_guard& operator=(const shared_lock_guard&) = delete;

        protected:
            _Lock&  m_Lock;
        };

    }
}
