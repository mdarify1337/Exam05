#include        "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() 
{}

TargetGenerator::TargetGenerator(const  TargetGenerator   &Spbook)
{
        *this = Spbook;
}

TargetGenerator   &TargetGenerator::operator=(const TargetGenerator   &Spbook)
{
        this->_TG = Spbook._TG;
        return *this;
}

void    TargetGenerator::learnTargetType(ATarget    *Spell)
{
        if (Spell)
            _TG[Spell->getType()] = Spell;
}

void    TargetGenerator::forgetTargetType(std::string  const &SpellName)
{
        if (_TG.find(SpellName) != _TG.end())
            _TG.erase(_TG.find(SpellName));
}

ATarget      *TargetGenerator::createTarget(std::string const &SpellName)
{
        ATarget *tmp = NULL;
        if (_TG.find(SpellName) != _TG.end())
            tmp = _TG[SpellName];
        return tmp;
}

TargetGenerator::~TargetGenerator()
{}