#include        "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::SpellBook(const  SpellBook   &Spbook)
{
        *this = Spbook;
}

SpellBook   &SpellBook::operator=(const SpellBook   &Spbook)
{
        this->_SP = Spbook._SP;
        return *this;
}

void    SpellBook::learnSpell(ASpell    *Spell)
{
        if (Spell)
            _SP[Spell->getName()] = Spell;
}

void    SpellBook::forgetSpell(std::string  const &SpellName)
{
        if (_SP.find(SpellName) != _SP.end())
            _SP.erase(_SP.find(SpellName));
}

ASpell      *SpellBook::createSpell(std::string const &SpellName)
{
        ASpell *tmp = NULL;
        if (_SP.find(SpellName) != _SP.end())
            tmp = _SP[SpellName];
        return tmp;
}

SpellBook::~SpellBook()
{}