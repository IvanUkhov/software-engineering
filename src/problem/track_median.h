#ifndef PROBLEM_TRACK_MEDIAN_H_
#define PROBLEM_TRACK_MEDIAN_H_

namespace problem {

// Numbers are randomly generated and stored into an (expanding) array. How
// would you keep track of the median?
template <typename T>
class MedianTracker {
 public:
  void Consume(T value) {}
  double Compute() const { return 0.0; }
};

} // namespace problem

#endif // PROBLEM_TRACK_MEDIAN_H_
