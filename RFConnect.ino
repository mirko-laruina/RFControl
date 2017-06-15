//Byte array we use as handshake
//Change it to match different transmitter/receiver
//Warning: if inizialized with a string, lenght must be HS_SIZE-1
#define HS_SIZE 3
const byte HS[HS_SIZE] = "Hi";

bool handShake(){
  while(Serial.available() == 0);
  while(Serial.read() != HS[0]);
  while(Serial.available() < HS_SIZE - 1); //first byte already read, wait until all handshake arrives
  bool good = true;
  for(int i = 1; i<HS_SIZE && good; ++i){
      if(HS[i] != Serial.read())
       good = false;
  }
  return good;
}

template< typename T > void rfWrite(const T& obj){
     Serial.write(HS, HS_SIZE);
     Serial.write((byte*)&obj, sizeof(obj));
}

template< typename T > void rfWrite( const T* obj, const int& size){
     //size is needed for arrays
     Serial.write(HS, HS_SIZE);
     Serial.write((byte*)obj, sizeof(*obj)*size);
}

template< typename T > void rfRead( T& obj){
    if(!handShake()) return;
    //while(Serial.available() < sizeof(obj));
    for(int i = 0; i<sizeof(obj); ++i){
        while(Serial.available()==0);
        *(((byte*)&obj) + i) = Serial.read();     
     }
}

template< typename T > void rfRead( T* obj, const int& size){
    if(!handShake()) return;
    //while(Serial.available() < sizeof(*obj)*size);
    for(int i = 0; i<sizeof(*obj)*size; ++i){
        while(Serial.available()==0);
        *(((byte*)obj) + i) = Serial.read();    
     }
}
