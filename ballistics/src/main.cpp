#include <chrono>
#include "core/engine.h"

static engine *engine_name;

int main(int argc, char *argv[])
{
  engine_name = new engine();

  engine_name->init();
  engine_name->run();
  engine_name->shutdown();
}
