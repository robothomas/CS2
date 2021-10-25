#include<iostream>

class ConeWeights {
  int num_cones;
  float *data;
public:
  // constructor
  ConeWeights(int n) { 
    num_cones = n; 
    data = new float[num_cones]; 
  }

  // destructor
  ~ConeWeights() { 
    std::cerr << "bye!" << std::endl; 
    delete [] data; 
  }

  void assign_cone_weight(int i, float w) { 
    data[i] = w; 
  }

  void read_weights() {
    for (int i = 0; i < num_cones; i++) {
        std::cerr << data[i] << ' ';
    }

    std::cerr << std::endl;
  }

  void triple_cone_weight() {
      for (int i = 0; i < num_cones; i++) {
          data[i] *= 3;
      }

      std::cerr << "Triped weights: ";
      read_weights();
  }

  void increase() {
    float *tempdata = new float[num_cones + 1];
    
    for (int i = 0; i < num_cones; i++) {
        tempdata[i] = data[i];
    }

    tempdata[++num_cones] = 0;

    std::cerr << "Increased array: ";
    read_weights();

    delete [] data;

    data = tempdata;

  }
  
  void display() { 
    std::cerr << "num_cones " << num_cones << std::endl;
  }
};

int main() {
  ConeWeights cs(3); // constructor is automatically called here
  cs.assign_cone_weight(0, 125.5);
  cs.assign_cone_weight(1, 62.1);
  cs.assign_cone_weight(2, 402.9);
  cs.triple_cone_weight();
  cs.increase();
  cs.increase();
  cs.display();
  // invisible feature:  the destructor is automatically called here!
}
