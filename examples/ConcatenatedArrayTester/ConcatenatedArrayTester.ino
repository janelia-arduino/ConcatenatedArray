#include <Arduino.h>
#include <Streaming.h>
#include <ConcatenatedArray.h>


const long BAUDRATE = 115200;

const size_t MAX_ARRAY_COUNT = 3;
ConcatenatedArray<int,MAX_ARRAY_COUNT> cat_array;

const size_t ARRAY_COUNT_0 = 6;
int array_0[ARRAY_COUNT_0];
const size_t ARRAY_COUNT_1 = 4;
int array_1[ARRAY_COUNT_1];
const size_t ARRAY_COUNT_2 = 2;
int array_2[ARRAY_COUNT_2];


void setup()
{
  Serial.begin(BAUDRATE);
  delay(1000);

  cat_array.addArray(array_0);
  cat_array.push_back(1);
  cat_array.push_back(2);
  cat_array.push_back(3);
  cat_array.push_back(4);
  Serial << "cat_array.size():" << endl;
  Serial << cat_array.size() << endl;
  Serial << "cat_array.max_size():" << endl;
  Serial << cat_array.max_size() << endl;
  Serial << "cat_array:" << endl;
  Serial << cat_array << endl;
  Serial << endl;

  cat_array.addArray(array_1);
  cat_array.push_back(10);
  cat_array.push_back(20);
  cat_array.push_back(30);
  Serial << "cat_array.size():" << endl;
  Serial << cat_array.size() << endl;
  Serial << "cat_array.max_size():" << endl;
  Serial << cat_array.max_size() << endl;
  Serial << "cat_array:" << endl;
  Serial << cat_array << endl;
  Serial << endl;

  cat_array.addArray(array_2);
  cat_array.push_back(100);
  cat_array.push_back(200);
  Serial << "cat_array.size():" << endl;
  Serial << cat_array.size() << endl;
  Serial << "cat_array.max_size():" << endl;
  Serial << cat_array.max_size() << endl;
  Serial << "cat_array:" << endl;
  Serial << cat_array << endl;

  Vector<int> & sub_vector = cat_array.subVector(1);
  Serial << "cat_array[1]:" << endl;
  Serial << sub_vector << endl;

}


void loop()
{
}
