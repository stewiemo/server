#ifndef MAP_TPL_MODULETEMPLATELOADER_H
#define MAP_TPL_MODULETEMPLATELOADER_H
#include <base/modulebase.h>

namespace ms
{
    namespace map
    {
        namespace tpl
        {
            class TemplateLoader;

            class ModuleTemplateLoader : public base::ModuleBase
            {
            public:
                static ModuleTemplateLoader* Create();

            protected:
                virtual ~ModuleTemplateLoader();

            private:
                ModuleTemplateLoader();
                virtual void OnModuleSetup() override;
                virtual void OnModuleCleanup() override;

                TemplateLoader* m_tploader = nullptr;
            };
        }
    }
}

#endif // MODULETEMPLATELOADER_H
