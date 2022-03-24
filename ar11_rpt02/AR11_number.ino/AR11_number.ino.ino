
#include <Wire.h>

#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  

int blinkNumber =0;

void setup() {
  // 9600bps로 시리얼 통신 설정  
  Serial.begin(9600);
  // 13번 핀을 출력으로 설정    
  lcd.noBacklight(blankNumber);
  delay(250);
  lcd.backlight(blankNumber);
  delay(250);
}

void loop() {
// 시리얼 통신으로 입력 받은 데이터가 있는지를 검사하여
// 데이터가 있을 경우에 if문 안의 명령어를 실행
  if(Serial.available()){       
  // val 변수에 시리얼 통신값 읽어오기
    char val=Serial.read();
    // 입력된 값이 0~9의 숫자인지를 판단
    if(isDigit(val)){
     // val은 ASCII 코드값이므로 숫자로 바꿔주기 위하여 
     // '0'의 아스키 코드값을 빼줌
     // blinkNumber에는 실제 숫자가 저장된다.
      blinkNumber=(val - '0');
    }
    if(blinkNumber <10){
    Serial.print("입력한 수 :");
    Serial.print(blinkNumber); 
   
    delay(500);
  }
  }
  // blinkNumber 만큼 LED를 점멸시킴  
    for(char i=0;i < blinkNumber;i++){  
    digitalWrite(ledPin,HIGH);
    delay(100*blinkNumber);
    digitalWrite(ledPin,LOW);
    delay(100);
   
  
  }
  // 점멸 횟수를 리셋함
  blinkNumber = 0;
}
