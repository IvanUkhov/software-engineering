#ifndef PROBLEM_EIGHT_QUEENS_H_
#define PROBLEM_EIGHT_QUEENS_H_

#include <algorithm>
#include <cstddef>

namespace problem {

// Write an algorithm to print all ways of arranging eight queens on an 8x8
// chess board so that none of them share the same row, column, or diagonal. In
// this case, “diagonal” means all diagonals, not just the two that bisect the
// board.
template <std::size_t N = 8>
class EightQueens {
 public:
  using Board = bool[N][N];

 protected:
  void Start();
  virtual void Commit(const Board& board) = 0;

 private:
  static const std::size_t M = 2 * N - 1;

  void Process(std::size_t i);

  void Reset() {
    std::fill(&board_[0][0], &board_[N][0], false);
    std::fill(&block_[0], &block_[N + M + M], false);
  }

  Board board_;
  bool block_[N + M + M];
};

template <std::size_t N>
void EightQueens<N>::Start() {
  Reset();
  Process(0);
}

template <std::size_t N>
void EightQueens<N>::Process(std::size_t i) {
  for (std::size_t j = 0; j < N; ++j) {
    auto k = N + i + j;
    auto l = N + M + i + N - 1 - j;
    if (block_[j] || block_[k] || block_[l]) continue;
    board_[i][j] = true;
    block_[j] = true;
    block_[k] = true;
    block_[l] = true;
    if (i + 1 == N) Commit(board_);
    else Process(i + 1);
    board_[i][j] = false;
    block_[j] = false;
    block_[k] = false;
    block_[l] = false;
  }
}

} // namespace problem

#endif // PROBLEM_EIGHT_QUEENS_H_
