#include    "Warlock.hpp"
#include    "Dummy.hpp"
#include    "Fwoosh.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl; 
}

std::string const &Warlock::getName() const
{
    return _name;
}

std::string const &Warlock::getTitle() const
{
    return _title;
}

void    Warlock::setTitle(std::string const &title)
{
    _title = title;
}

void    Warlock::introduce()    const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}


void    Warlock::learnSpell(ASpell  *Spell)
{
        if (Spell)
            _SP[Spell->getName()] = Spell;
}

void    Warlock::forgetSpell(std::string    SpellName)
{
        if (_SP.find(SpellName) != _SP.end())
            _SP.erase(_SP.find(SpellName));
}

void    Warlock::launchSpell(std::string SpellName, const ATarget &Target)
{
        if (_SP.find(SpellName) != _SP.end())
            _SP[SpellName]->launch(Target);
}

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
