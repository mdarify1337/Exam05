#pragma     once
#include    "ASpell.hpp"

class       ASpell;

class       ATarget
{
            protected:
                    std::string     _type;
            public:
                    ATarget(std::string type);
                    ATarget(const ATarget &Target);
                    ATarget &operator=(const ATarget    &Target);
                    virtual     ~ATarget();
                    std::string     getType()   const;
                    virtual     ATarget     *clone()    const = 0;
                    void        getHitBySpell(const     ASpell &Spell) const;
};