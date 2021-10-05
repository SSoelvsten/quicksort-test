go_bandit([]() {
    describe("Quicksort Algorithm", []() {
        it("can sort a randomly ordered list", [&]() {
            std::vector<int> v = {4, 9, 5, 0, 3, 2, 8, 6, 7, 1};

            const qs::stats_t sorting_stats = qs::sort(v, std::less<int>());

            for (int i = 0; i < v.size(); i++) {
              AssertThat(v[i], Is().EqualTo(i));
            }
          });

        it("can sort an in-order list", [&]() {
            std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

            const qs::stats_t sorting_stats = qs::sort(v, std::less<int>());

            for (int i = 0; i < v.size(); i++) {
              AssertThat(v[i], Is().EqualTo(i));
            }
          });

        it("can sort a reversely ordered list", [&]() {
            std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

            const qs::stats_t sorting_stats = qs::sort(v, std::greater<int>());

            for (int i = 0; i < v.size(); i++) {
              AssertThat(v[i], Is().EqualTo(v.size() - i - 1));
            }
         });
      });
  });
