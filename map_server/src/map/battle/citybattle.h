#ifndef MAP_BATTLE_CITYBATTLE_H
#define MAP_BATTLE_CITYBATTLE_H
#include "battle.h"
#include <stdint.h>

namespace ms
{
    namespace map
    {
        class FamousCity;
        class Capital;
        namespace battle
        {
            class CityBattle : public Battle
            {
            public:
                CityBattle(Troop* troop, FamousCity* city);
                virtual ~CityBattle();

                virtual void OnStart() override;
                virtual void OnEnd(model::AttackType winner, int reportId, bool last_flag) override;
                virtual void OnBattleEnd(model::AttackType winner) override;

                msgqueue::MsgWorldBossInfo& worldBossInfo() const {
                    return *m_worldBossInfo;
                }
            protected:
                virtual void SetDefenseInput( engine::InitialDataInput& defenseInput) override;

            protected:
                FamousCity* m_city = nullptr;
                Unit*       m_unit = nullptr;
                std::vector<model::tpl::DropItem> m_dorpItems;
                
                msgqueue::MsgWorldBossInfo* m_worldBossInfo = nullptr;
                                
                ArmyList m_defCache;
                TrapSet m_trapCache;
            };
        }
    }
}

#endif // MAP_BATTLE_CITYBATTLE_H
