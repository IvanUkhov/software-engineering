#include "gtest/gtest.h"
#include "problem/eight_queens.h"

class EightQueens: protected problem::EightQueens<> {
 public:
  EightQueens() {
    Start();
  }

  std::size_t Count() const {
    return count_;
  }

 protected:
  void Commit(const Board& board) override {
    ++count_;
  }

 private:
  std::size_t count_ = 0;
};

TEST(ProblemTest, EightQueens) {
  ASSERT_EQ(EightQueens().Count(), 92);
}
