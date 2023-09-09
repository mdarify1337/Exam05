#pragma     once

#include        "ATarget.hpp"
#include        <map>

class       ATarget;
class       TargetGenerator
{
            private:
                    TargetGenerator(const   TargetGenerator &Tgenerator);
                    TargetGenerator &operator=(const TargetGenerator &Tgenerator);
                    std::map<std::string, ATarget *> _TG;
            public:
                    TargetGenerator();
                    ~TargetGenerator();
                    void    learnTargetType(ATarget *Target);
                    void    forgetTargetType(std::string const &Tgenerator);
                    ATarget *createTarget(std::string const &Tgenerator);
};