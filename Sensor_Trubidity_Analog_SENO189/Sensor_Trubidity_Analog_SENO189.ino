int pinTurb = A0; // pin analog A0
float V;          //reset
float kekeruhan;
float Vrata2;
float Vhasil;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// baut rate 9600 for communication serial
  delay(2000);       // 2 detik
  Serial.println("===========");
  Serial.println("Sensor Kekeruhan Air");
  Serial.println("============");
}

void loop() {
  // put your main code here, to run repeatedly:

//  inisialisasi dengan 0 untuk variable volt
    V =0; //reset nilai 0
    // dibaca nilai analog yang akan dikonversi ke bentuk tegangan 
    for(int i=0; i<800; i++){
      V +=((float)analogRead(pinTurb)/1023)*5;
    }
//   rata2 hasil tengan
    Vrata2 = V/800;
//    bulatkan angka 1 dibelakang koma
    Vhasil = roundf(Vrata2*10.0f)/10.0f;

    if(Vhasil < 2.5){
      //sesuai grafik datashet
      kekeruhan = 3000;
    }else{
      kekeruhan = -1120.4*square(Vhasil)+5742.3*Vhasil-4353.8;
    }


  Serial.print("tegangan : ");
  Serial.print(Vhasil);
  Serial.print("V");

  Serial.print("\t  kekeruhan : ");
  Serial.print(kekeruhan);
  Serial.println();
  delay(100);

}
