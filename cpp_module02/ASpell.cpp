#include    "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effect) : _name(name), _effects(effect)
{}

ASpell::ASpell(const ASpell &Spell)
{
    *this = Spell;
}

ASpell  &ASpell::operator=(const ASpell &Spell)
{
    this->_name = Spell._name;
    this->_effects = Spell._effects;
    return *this;
}

std::string     ASpell::getName()   const
{
    return _name;
}

std::string     ASpell::getEffects()    const
{
    return  _effects;
}

void    ASpell::launch(const    ATarget &Target) const
{
    Target.getHitBySpell(*this);
}

ASpell::~ASpell()
{}