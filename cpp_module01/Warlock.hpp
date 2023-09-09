#pragma         once
#include    <iostream>
#include        <map>
#include        "ASpell.hpp"

class       ASpelll;
class       Warlock
{
            private:
                    std::string     _name;
                    std::string     _title;
                    Warlock();
                    Warlock(const Warlock   &lock);
                    Warlock &operator=(const    Warlock &lock);
                    std::map<std::string, ASpell        *>_SP;
            public:
                    Warlock(std::string const &name, std::string  const &title);
                    ~Warlock();
                    std::string   const   &getName() const;
                    std::string     const &getTitle() const;
                    void    setTitle(std::string const &title);
                    void    introduce() const;
                    void        learnSpell(ASpell       *Spell);
                    void        forgetSpell(std::string SpellName);
                    void        launchSpell(std::string SpellName, const ATarget        &Target);
};