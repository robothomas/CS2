#include<iostream>

class UltimateFrisbee {
  int size;
  float *data;
public:
  UltimateFrisbee() { size = 0; data = 0; }

  UltimateFrisbee(int s) { size = s; data = new float[size]; }

  UltimateFrisbee(UltimateFrisbee &uCopy) {
      size = uCopy.size;
      data = new float[size];
  }


  ~UltimateFrisbee() {
    std::cerr << "bye!" << std::endl;
    if ( data ) delete [] data;
  }

  void display()
    { std::cerr << "size " << size << std::endl;}
};

int main()
{
  UltimateFrisbee g1, g2(3);

  g1.display();
  g2.display();
}
