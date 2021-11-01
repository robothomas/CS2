#include<iostream>

class ConeWeights {
  int num_cones;
  float *data;
public:
  // constructors
  ConeWeights(int n) { 
    num_cones = n; 
    data = new float[num_cones]; 
  }

  ConeWeights(const ConeWeights &c) {
    num_cones = c.num_cones;
    data = new float[num_cones];
    for (int i = 0; i < num_cones; ++i) { 
      data[i] = c.data[i];
    }
  }

  ConeWeights &operator=(const ConeWeights &c) { // version 4
    num_cones = c.num_cones;
    delete [] data;
    data = new float[c.num_cones];
    for (int i = 0; i < c.num_cones; ++i) {
      data[i] = c.data[i];
    }
    return *this;
  }


  // destructor
  ~ConeWeights() { 
    std::cerr << "bye!" << std::endl; 
    delete [] data; 
  }

  void assign_cone_weight(int i, float w) { 
    data[i] = w; 
  }

  void display() { 
    std::cerr << "num_cones " << num_cones << std::endl;
  }
};

int main() {
  ConeWeights c1(3), c2(4), c3(5);
  c1.assign_cone_weight(0, 125.5);
  c2 = c1;
  c2.display();

  std::cerr << "Before triple equalizer" << std::endl << "c1" << std::endl;
  c1.display();
  std::cerr << "c2" << std::endl;
  c2.display();
  std::cerr << "c3" << std::endl;
  c3.display();

  c1 = c2 = c3;

  std::cerr << "After triple equalizer" << std::endl << "c1" << std::endl;
  c1.display();
  std::cerr << "c2" << std::endl;
  c2.display();
  std::cerr << "c3" << std::endl;
  c3.display();

}
