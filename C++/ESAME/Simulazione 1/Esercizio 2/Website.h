#ifndef WEBSITE_H
#define WEBSITE_H

#include "Webpage.h"


class Website{
private:
    Webpage* homepage;
public:
    Website(Webpage* hp);

    int find_webpage(const Webpage& target) const;
};

#endif
