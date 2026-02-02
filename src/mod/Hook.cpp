#include "mod/MyMod.h"

#include <ll/api/memory/Hook.h>
#include <mc/world/actor/Actor.h>
#include <mc/world/actor/Mob.h>
#include <mc/world/actor/ai/goal/BreedGoal.h>

namespace my_mod::hook {

LL_TYPE_INSTANCE_HOOK(ActorCanMateHook, HookPriority::Normal, Actor, &Actor::canMate, bool, ::Actor const& partner) {
    if (hasCategory(ActorCategory::Villager)) {
        return false;
    } else {
        return origin(partner);
    }
}

void hook() {
    ActorCanMateHook::hook();
}

} // namespace my_mod::hook