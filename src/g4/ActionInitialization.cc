#include "g4/ActionInitialization.hh"
#include "g4/PrimaryGeneratorAction.hh"

namespace edu0bm412 {

void ActionInitialization::BuildForMaster() const {
}

void ActionInitialization::Build() const {
  SetUserAction(new PrimaryGeneratorAction);
}

}
