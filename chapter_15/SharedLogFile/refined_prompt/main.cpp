#include "SharedLogFile.hpp"
#include <thread>

int main() {
  SharedLogFile::Options opts;
  opts.bufferedBytes = 128 * 1024;
  opts.flushPolicy = SharedLogFile::FlushPolicy::FlushOnNewline;

  SharedLogFile logger("app.log", opts);

  std::thread t1([&] { logger.writeln("Thread 1: started"); });
  std::thread t2([&] { logger.writeln("Thread 2: started"); });

  t1.join();
  t2.join();

  logger.writeln("Main: shutting down");
  logger.flush();
}
