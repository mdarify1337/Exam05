#include        "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{}

ATarget::ATarget(const ATarget &Target)
{
    *this = Target;
}

ATarget     &ATarget::operator=(const   ATarget     &Target)
{
    this->_type = Target._type;
    return  *this;
}

std::string     ATarget::getType()  const
{
    return  _type;
}


void        ATarget::getHitBySpell(const    ASpell  &Spell) const
{
    std::cout << _type << " has been " << Spell.getEffects() << "!" << std::endl;
}

ATarget::~ATarget()
{}