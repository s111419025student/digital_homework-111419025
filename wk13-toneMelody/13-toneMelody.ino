// --- 1. 預先定義音高頻率 (對應投影片提到的中音域 Hz) ---
#define NOTE_C4  262 // Do
#define NOTE_D4  294 // Re
#define NOTE_E4  330 // Mi
#define NOTE_F4  349 // Fa
#define NOTE_G4  392 // Sol
#define NOTE_A4  440 // La
#define NOTE_B4  494 // Si
#define NOTE_C5  523 // 高音 Do

int LEDState;

// --- 2. 建立旋律陣列 (這裡示範播放 Do Re Mi Fa Sol La Si Do，共 8 個音) ---
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

// --- 3. 建立節拍陣列 (4 代表四分音符) ---
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};

int ledPin[] = {
  2, 3, 4, 5, 6, 7, 8, 9
};

void setup() {
  // 使用 tone() 指令不需要特別在 setup 裡設定 pinMode OUTPUT
  for (int i=0;i<8;i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  // ==========================================
  // 以下是投影片圖片中的核心程式碼
  // ==========================================
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    
    // 計算每個音符的持續時間
    int noteDuration = 1000 / noteDurations[thisNote];
    
    // 讓接在腳位 8 的蜂鳴器發聲
    tone(10, melody[thisNote], noteDuration);
    digitalWrite(ledPin[thisNote],HIGH);
    LEDState=ledPin[thisNote];
    
    // 設定音符之間的停頓時間 (音符長度的 1.3 倍)
    int pauseBetweenNotes = noteDuration * 1.3;
    delay(pauseBetweenNotes);
    digitalWrite(ledPin[thisNote],LOW);
    
    // 停止腳位 8 的發聲
    noTone(10);
  }
  
  // 播完 8 個音符後，停頓 200 毫秒再從頭開始迴圈
  delay(200); 
}