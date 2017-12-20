#include "gtest/gtest.h"
#include "structure/queue/impartial.h"

const std::size_t kCount = 100;

using Queue = structure::queue::Impartial<int>;

TEST(QueueTest, ImpartialEnqueueDequeue) {
  Queue queue;
  for (int i = 0; i < kCount; ++i) {
    queue.Enqueue(i);
  }
  for (int i = kCount - 1; i >= 0; --i) {
    ASSERT_EQ(queue.Dequeue(), i);
  }
}
