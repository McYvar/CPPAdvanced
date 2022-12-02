
#include "Decorator.h"
#include "Elve.h"
#include "RoleDecorator.h"

int main(int argc, char* argv[])
{
    auto Eric = new Elve("Eric");
    Eric->Render();

    auto Joseph = new RoleDecorator(new Elve("Joseph"), Shaman);
    Joseph->Render();

    auto Ender = new RoleDecorator(
                    new RoleDecorator(
                        new RoleDecorator(
                            new Orc("Ender"),
                            Farmer),
                        Soldier),
                    Shaman);
    Ender->Render();

    delete Eric;
    delete Joseph;
    delete Ender;
    return 0;
}
