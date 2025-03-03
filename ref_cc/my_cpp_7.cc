#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void ShortArgs(int a, int b, int c, int d, int e, int f, int g, int h, int i,
               int j) {
  std::cout << "ShortArgs called" << std::endl;
}

void ShortParams(int x, int y, int z, int u, int v, int w, int m, int n, int o,
                 int p) {
  std::cout << "ShortParams called" << std::endl;
}

void LongArgs(int number_of_users, int maximum_capacity, int minimum_limit,
              int average_count, int threshold_value, int computation_result,
              int session_duration, int retry_attempts, int accumulated_total,
              int active_instances) {
  std::cout << "LongArgs called" << std::endl;
}

void LongParams(int database_connection_timeout, int number_of_retries,
                int cache_refresh_interval, int network_bandwidth,
                int user_session_expiry, int allowed_login_attempts,
                int concurrent_thread_limit, int background_process_count,
                int max_open_files, int disk_read_latency) {
  std::cout << "LongParams called" << std::endl;
}

void MixedArgs(int a, int max_limit, int c, int user_session, int e,
               int threshold, int g, int count, int i, int retry) {
  std::cout << "MixedArgs called" << std::endl;
}

void STLFunctionTest() {
  std::vector<int> numbers = {1, 2, 3, 4, 5};
  std::map<std::string, int> word_counts = {{"apple", 3}, {"banana", 2}};

  std::for_each(numbers.begin(), numbers.end(), [](int value) {
    std::cout << "Processing: " << value << std::endl;
  });
}

template <typename T1, typename T2, typename T3, typename T4, typename T5,
          typename T6, typename T7, typename T8, typename T9, typename T10>
class TemplateWithManyParams {
 public:
  void Display() {
    std::cout << "TemplateWithManyParams instantiated" << std::endl;
  }
};

int main() {
  ShortArgs(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  ShortParams(10, 20, 30, 40, 50, 60, 70, 80, 90, 100);
  LongArgs(11111111, 22222222, 33333333, 44444444, 55555555, 66666666, 77777777,
           88888888, 99999999, 1010101010);
  LongParams(11111111, 22222222, 33333333, 44444444, 55555555, 66666666,
             77777777, 88888888, 99999999, 1010101010);
  MixedArgs(11111111, 22222222, 33333333, 44444444, 55555555, 6, 7, 8, 9,
            1010101010);
  MixedArgs(1, 2, 3, 44444444, 55555555, 66666666, 77777777, 88888888, 99999999,
            10);
  STLFunctionTest();

  TemplateWithManyParams<int, double, std::string, char, float, long, short,
                         unsigned, bool, std::vector<int>>
      t;
  t.Display();

  return 0;
}
