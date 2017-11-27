#ifndef INTERVIEW_STRUCTURE_TREE_HEAP_BINARY_H_
#define INTERVIEW_STRUCTURE_TREE_HEAP_BINARY_H_

#include <vector>

template <typename T>
void Down(std::vector<T>& data, int i, int size);

template <typename T>
void Up(std::vector<T>& data, int i);

template <typename T>
class Binary {
 public:
  typedef std::vector<T> Container;
  typedef typename Container::size_type SizeType;

  Binary() {}
  Binary(Container data);

  void Arrange();
  T Pop();
  void Push(T value);
  SizeType Size() const;

 private:
  Container data_;
};

template <typename T>
Binary<T>::Binary(Container data) : data_(data) {
  this->Arrange();
}

template <typename T>
void Binary<T>::Arrange() {
  int size = (int)this->Size();
  for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
    Down(this->data_, i, size);
  }
}

template <typename T>
T Binary<T>::Pop() {
  int size = (int)this->Size() - 1;
  T value = this->data_[0];
  this->data_[0] = this->data_[size];
  this->data_.pop_back();
  Down(this->data_, 0, size);
  return value;
}

template <typename T>
void Binary<T>::Push(T value) {
  this->data_.push_back(value);
  Up(this->data_, (int)this->Size() - 1);
}

template <typename T>
typename Binary<T>::SizeType Binary<T>::Size() const {
  return this->data_.size();
}

template <typename T>
void Down(std::vector<T>& data, int i, int size) {
  while (true) {
    int j = 2 * i + 1;
    if (j >= size) {
      return;
    }
    int k = j + 1;
    if (k < size && data[k] > data[j]) {
      j = k;
    }
    T value = data[i];
    if (data[j] <= value) {
      return;
    }
    data[i] = data[j];
    data[j] = value;
    i = j;
  }
}

template <typename T>
void Up(std::vector<T>& data, int i) {
  while (i > 0) {
    int j = (i - 1) / 2;
    T value = data[i];
    if (data[j] >= value) {
      return;
    }
    data[i] = data[j];
    data[j] = value;
    i = j;
  }
}

#endif // INTERVIEW_STRUCTURE_TREE_HEAP_BINARY_H_
