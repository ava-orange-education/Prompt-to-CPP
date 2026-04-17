#include "SharedLogger_weak_prompt.hpp"
#include <thread>

int main() {
  SharedLogger logger("application.log");

  std::thread t1([&]() { logger.log("Thread 1 started"); });

  std::thread t2([&]() { logger.log("Thread 2 started"); });

  t1.join();
  t2.join();

  logger.log("Application shutting down");
}
