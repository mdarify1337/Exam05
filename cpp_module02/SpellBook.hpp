#pragma     once

#include    "ASpell.hpp"
#include    "ATarget.hpp"
#include    <map>

class       ASpell;
class       ATarget;

class       SpellBook
{
            private:
                    SpellBook(const SpellBook   &SBook);
                    SpellBook   &operator=(const SpellBook   &SBook);
                    std::map<std::string, ASpell *> _SP;
            public:
                    SpellBook();
                    ~SpellBook();
                    void    learnSpell(ASpell *Spell);
                    void    forgetSpell(std::string const &SpellName);
                    ASpell  *createSpell(std::string const &SpellName);
};