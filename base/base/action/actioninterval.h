#ifndef BASE_ACTION_ACTIONINTERVAL_H
#define BASE_ACTION_ACTIONINTERVAL_H

#include "actionbase.h"

namespace base
{
    namespace action
    {
        class ActionInterval : public ActionBase
        {
        public:
            ActionInterval(int32_t interval);
            virtual ~ActionInterval();

            virtual const char* GetObjectName() {
                return "base::action::ActionInterval";
            }

            void SetInterval(int32_t interval) {
                interval_ = interval;
                acc_ = 0;
            }

        private:
            virtual void OnUpdate(int64_t tick, int32_t span);
            virtual void OnInterval(int64_t tick, int32_t span) = 0;

            int32_t interval_;
            int32_t acc_;
        };
    }
}

#endif // ACTIONINTERVAL_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
