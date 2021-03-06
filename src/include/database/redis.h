#include <iostream>
#include <random>
#include <thread>

#include <hiredis/hiredis.h>
#include <spdlog/spdlog.h>

#pragma once

#include <database/database.h>

class Redis : public Database {
private:
  int set_value(const std::string &, const std::string &);
  int get_value(const std::string &, std::string *);
  std::mutex mtx;

public:
  Redis(const std::string &, int);
  ~Redis() override;
  int initialize() override;
  int create_user(user) override;
  std::vector<std::string> list_users() override;
  int64_t count_user() override;
};
