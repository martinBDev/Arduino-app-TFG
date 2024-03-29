#include <ArduinoBLE.h>

// Define el UUID del servicio y las características
#define SERVICE_UUID      "180D"
//Codigo 180D para servicios cardiacos, 
//como se define en la pagina 69 del estandar:
// https://www.bluetooth.com/specifications/assigned-numbers/

#define PULSACIONES_UUID  "2A37" // Heart Rate Measurement 2A37, PAGINA 87 DEL ESTANDAR
#define OXIGENO_UUID      "2A58" //No existe un estandar para el oxigeno, usamos UUID sin asignar
#define AZUCAR_UUID       "2A59" //No existe un estandar para el azucar, usamos UUID sin asignar
#define PRESION_UUID      "2A49" //Blood Pressure Measurement 2A49, PAGINA 83 DEL ESTANDAR


unsigned long ultima_lectura = 0; //Variable usada para hacer una medicion cada 5 segundos
const long intervalo = 15000; //Milisegundos

String linked_user = ""; //Primer usuario en conectarse. 
//Solo se permitirá a este usuario conectarse hasta que se reinicie el dispositivo

//Creacion de servicio y sus caracteristicas
BLEService ritmoCardiacoService(SERVICE_UUID); // Crea el servicio de ritmo cardiaco
BLEIntCharacteristic pulsacionesCharacteristic(PULSACIONES_UUID, BLERead | BLENotify ); // Característica de pulsaciones por minuto
BLEIntCharacteristic oxigenoCharacteristic(OXIGENO_UUID, BLERead | BLENotify ); // Característica de porcentaje de oxígeno en sangre
BLEIntCharacteristic azucarCharacteristic(AZUCAR_UUID, BLERead | BLENotify ); // Característica de nivel de azúcar
BLEIntCharacteristic presionCharacteristic(PRESION_UUID, BLERead | BLENotify ); // Característica presion sistolica


int  bpm = random(30, 200);
int  o2Percent = random(80, 100); 
int  sugarLevel = random(50, 135); 
int  presion = random(45, 150); 



void hacer_lectura(){

  Serial.println("lECTURA");
 bpm = random(30, 200);
  o2Percent = random(80, 100);
  sugarLevel = random(50, 135);
  presion = random(45, 150);
}

void setup() {
 Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("No se pudo iniciar BLE!");
    while (1);
  }
  

  // Se publica dispositivo BLE
  BLE.setLocalName("TuCorazon");
  BLE.setDeviceName("TuCorazon");
  BLE.setAdvertisedService(ritmoCardiacoService);

   // Agrega las características al servicio
  ritmoCardiacoService.addCharacteristic(pulsacionesCharacteristic);
  ritmoCardiacoService.addCharacteristic(oxigenoCharacteristic);
  ritmoCardiacoService.addCharacteristic(azucarCharacteristic);
  ritmoCardiacoService.addCharacteristic(presionCharacteristic);

   // Publica el servicio BLE
  BLE.addService(ritmoCardiacoService);

  // Empieza la conexión BLE
  BLE.advertise();

  Serial.println("Esperando conexión BLE...");
  
}


void loop() {

   
  // Espera una conexión BLE
  BLEDevice central = BLE.central();

    if (central) {

        Serial.print("Conectado: ");
        Serial.println(central.address());
        
        linked_user  = central.address();
        // Mientras esté conectado
        while (central.connected()) {

          

            if(millis() - ultima_lectura >= intervalo){
              hacer_lectura();
              ultima_lectura = millis();


              pulsacionesCharacteristic.writeValue(bpm); //1 byte
              Serial.print("bpm:");
              Serial.println(bpm);
              
              oxigenoCharacteristic.writeValue(o2Percent);
              Serial.print("o2Percent:");
              Serial.println(o2Percent);
    
              azucarCharacteristic.writeValue(sugarLevel);
              Serial.print("sugarLevel:");
              Serial.println(sugarLevel);
              
    
              presionCharacteristic.writeValue(presion);
              Serial.print("presion:");
              Serial.println(presion);
              
             // while (!central.connected() && central.address() != linked_user){
                //Serial.println("Esperando conexión...");
                
              //}
            }  
        }

        Serial.print("Desconectado de ");
        Serial.println(central.address());

  }
}
