#ifndef PROBLEM_BUILD_ORDER_H_
#define PROBLEM_BUILD_ORDER_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace problem {

// You are given a list of projects and a list of dependencies (which is a list
// of pairs of projects, where the second project is dependent on the first
// project). All of a project’s dependencies must be built before the project
// is. Find a build order that will allow the projects to be built. If there is
// no valid build order, return an error.
std::vector<std::size_t> BuildOrder(
    const std::vector<std::size_t>& projects,
    const std::vector<std::pair<std::size_t, std::size_t>>& dependencies);

} // namespace problem

#endif // PROBLEM_BUILD_ORDER_H_
