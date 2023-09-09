#include    "Warlock.hpp"
#include    "Dummy.hpp"
#include    "Fwoosh.hpp"
#include    "Fireball.hpp"
#include    "Polymorph.hpp"
#include    "BrickWall.hpp"
#include    "SpellBook.hpp"
#include    "TargetGenerator.hpp"

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
            _SP.learnSpell(Spell);
}

void    Warlock::forgetSpell(std::string    SpellName)
{
            _SP.forgetSpell(SpellName);
}

void    Warlock::launchSpell(std::string SpellName, const ATarget &Target)
{
        if (_SP.createSpell(SpellName))
            _SP.createSpell(SpellName)->launch(Target);
}

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}
