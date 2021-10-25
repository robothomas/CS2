#include<iostream>

int item_count;
double *item_price;

void print_items() {
  for (int i = 0; i < item_count; ++i) {
    std::cerr << item_price[i] << ' ';
  }

  std::cerr << std::endl; // added to create a new line after this outputs goes through
}

void change_items() {
  delete [] item_price;
  item_count = 3;
  item_price = new double[item_count];
  item_price[0] = 9;
  item_price[1] = 11;
  item_price[2] = 13;
}

void double_items() {
  double *new_item_price = new double[item_count * 2];

  int k = 0; 

  for (int i = 0; i < item_count * 2; i += 2) {
    new_item_price[i] = item_price[k];
    new_item_price[i + 1] = item_price[k];

    k++;
  }

  item_count *= 2; // to make the new item count reflect the new pointer
  
  delete [] item_price; // get rid of previous, now unused memory
  
  item_price = new_item_price;
}

int main() {
  item_count = 2;
  item_price = new double[item_count];
  item_price[0] = 5;
  item_price[1] = 7;
  print_items();
  change_items();
  print_items();
  double_items();
  double_items();
  print_items();
  delete [] item_price;
}
