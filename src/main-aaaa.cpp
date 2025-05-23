// /***************************************************
//   This is our GFX example for the Adafruit ILI9488 Breakout and Shield
//   ----> http://www.adafruit.com/products/1651

//   Check out the links above for our tutorials and wiring diagrams
//   These displays use SPI to communicate, 4 or 5 pins are required to
//   interface (RST is optional)
//   Adafruit invests time and resources providing this open source code,
//   please support Adafruit and open-source hardware by purchasing
//   products from Adafruit!

//   Written by Limor Fried/Ladyada for Adafruit Industries.
//   MIT license, all text above must be included in any redistribution
//  ****************************************************/


//  #include <SPI.h>
//  #include <Adafruit_GFX.h>
//  #include <ILI9488.h>
//  #include <XPT2046_Touchscreen.h>
 
//  #define TOUCH_CS		21
//  #define TOUCH_PEN		16
//  #define TFT_CS         4
//  #define TFT_DC         17
//  #define TFT_LED        22
//  #define TFT_RST        15
 
//  // Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
//  //ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);
//  // If using the breakout, change pins as desired
//  ILI9488 tft = ILI9488(TFT_CS, TFT_DC, MOSI, SCK, TFT_RST, MISO);
//  XPT2046_Touchscreen ts = XPT2046_Touchscreen(TOUCH_CS, TOUCH_PEN);

 
//  void setup() {
//    Serial.begin(9600);
//    Serial.println("ILI9488 Test!");
 
//    digitalWrite(TFT_CS, HIGH);
//    digitalWrite(TOUCH_CS, HIGH);

//    tft.begin();
 
//    // read diagnostics (optional but can help debug problems)
//    uint8_t x = tft.readcommand8(ILI9488_RDMODE);
//    Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
//    x = tft.readcommand8(ILI9488_RDMADCTL);
//    Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
//    x = tft.readcommand8(ILI9488_RDPIXFMT);
//    Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
//    x = tft.readcommand8(ILI9488_RDIMGFMT);
//    Serial.print("Image Format: 0x"); Serial.println(x, HEX);
//    x = tft.readcommand8(ILI9488_RDSELFDIAG);
//    Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX);
 
//    Serial.println(F("Benchmark                Time (microseconds)"));
 
//    Serial.print(F("Text                     "));
//    Serial.println(testText());
//    delay(3000);
 
//    Serial.println(F("Done!"));

//    digitalWrite(TFT_CS, HIGH);
//    digitalWrite(TOUCH_CS, LOW);
//    ts.begin();
//  }
 
 
//  void loop(void) {
// 	if (ts.touched()) {
// 		TS_Point p = ts.getPoint();
// 		Serial.print("Pressure = ");
// 		Serial.print(p.z);
// 		Serial.print(", x = ");
// 		Serial.print(p.x);
// 		Serial.print(", y = ");
// 		Serial.print(p.y);
// 		delay(30);
// 		Serial.println();
// 	  }
//  }
 
//  unsigned long testFillScreen() {
//    unsigned long start = micros();
//    tft.fillScreen(ILI9488_BLACK);
//    tft.fillScreen(ILI9488_RED);
//    tft.fillScreen(ILI9488_GREEN);
//    tft.fillScreen(ILI9488_BLUE);
//    tft.fillScreen(ILI9488_BLACK);
//    return micros() - start;
//  }
 
//  unsigned long testText() {
//    tft.fillScreen(ILI9488_BLACK);
//    unsigned long start = micros();
//    tft.setCursor(0, 0);
//    tft.setTextColor(ILI9488_WHITE);  tft.setTextSize(1);
//    tft.println("Hello World!");
//    tft.setTextColor(ILI9488_YELLOW); tft.setTextSize(2);
//    tft.println(1234.56);
//    tft.setTextColor(ILI9488_RED);    tft.setTextSize(3);
//    tft.println(0xDEADBEEF, HEX);
//    tft.println();
//    tft.setTextColor(ILI9488_GREEN);
//    tft.setTextSize(5);
//    tft.println("Groop");
//    tft.setTextSize(2);
//    tft.println("I implore thee,");
//    tft.setTextSize(1);
//    tft.println("my foonting turlingdromes.");
//    tft.println("And hooptiously drangle me");
//    tft.println("with crinkly bindlewurdles,");
//    tft.println("Or I will rend thee");
//    tft.println("in the gobberwarts");
//    tft.println("with my blurglecruncheon,");
//    tft.println("see if I don't!");
//    return micros() - start;
//  }
 
//  unsigned long testLines(uint16_t color) {
//    unsigned long start, t;
//    int           x1, y1, x2, y2,
// 				 w = tft.width(),
// 				 h = tft.height();
 
//    tft.fillScreen(ILI9488_BLACK);
 
//    x1 = y1 = 0;
//    y2    = h - 1;
//    start = micros();
//    for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    x2    = w - 1;
//    for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    t     = micros() - start; // fillScreen doesn't count against timing
 
//    tft.fillScreen(ILI9488_BLACK);
 
//    x1    = w - 1;
//    y1    = 0;
//    y2    = h - 1;
//    start = micros();
//    for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    x2    = 0;
//    for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    t    += micros() - start;
 
//    tft.fillScreen(ILI9488_BLACK);
 
//    x1    = 0;
//    y1    = h - 1;
//    y2    = 0;
//    start = micros();
//    for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    x2    = w - 1;
//    for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    t    += micros() - start;
 
//    tft.fillScreen(ILI9488_BLACK);
 
//    x1    = w - 1;
//    y1    = h - 1;
//    y2    = 0;
//    start = micros();
//    for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//    x2    = 0;
//    for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
 
//    return micros() - start;
//  }
 
//  unsigned long testFastLines(uint16_t color1, uint16_t color2) {
//    unsigned long start;
//    int           x, y, w = tft.width(), h = tft.height();
 
//    tft.fillScreen(ILI9488_BLACK);
//    start = micros();
//    for(y=0; y<h; y+=5) tft.drawFastHLine(0, y, w, color1);
//    for(x=0; x<w; x+=5) tft.drawFastVLine(x, 0, h, color2);
 
//    return micros() - start;
//  }
 
//  unsigned long testRects(uint16_t color) {
//    unsigned long start;
//    int           n, i, i2,
// 				 cx = tft.width()  / 2,
// 				 cy = tft.height() / 2;
 
//    tft.fillScreen(ILI9488_BLACK);
//    n     = min(tft.width(), tft.height());
//    start = micros();
//    for(i=2; i<n; i+=6) {
// 	 i2 = i / 2;
// 	 tft.drawRect(cx-i2, cy-i2, i, i, color);
//    }
 
//    return micros() - start;
//  }
 
//  unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
//    unsigned long start, t = 0;
//    int           n, i, i2,
// 				 cx = tft.width()  / 2 - 1,
// 				 cy = tft.height() / 2 - 1;
 
//    tft.fillScreen(ILI9488_BLACK);
//    n = min(tft.width(), tft.height());
//    for(i=n; i>0; i-=6) {
// 	 i2    = i / 2;
// 	 start = micros();
// 	 tft.fillRect(cx-i2, cy-i2, i, i, color1);
// 	 t    += micros() - start;
// 	 // Outlines are not included in timing results
// 	 tft.drawRect(cx-i2, cy-i2, i, i, color2);
//    }
 
//    return t;
//  }
 
//  unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
//    unsigned long start;
//    int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;
 
//    tft.fillScreen(ILI9488_BLACK);
//    start = micros();
//    for(x=radius; x<w; x+=r2) {
// 	 for(y=radius; y<h; y+=r2) {
// 	   tft.fillCircle(x, y, radius, color);
// 	 }
//    }
 
//    return micros() - start;
//  }
 
//  unsigned long testCircles(uint8_t radius, uint16_t color) {
//    unsigned long start;
//    int           x, y, r2 = radius * 2,
// 				 w = tft.width()  + radius,
// 				 h = tft.height() + radius;
 
//    // Screen is not cleared for this one -- this is
//    // intentional and does not affect the reported time.
//    start = micros();
//    for(x=0; x<w; x+=r2) {
// 	 for(y=0; y<h; y+=r2) {
// 	   tft.drawCircle(x, y, radius, color);
// 	 }
//    }
 
//    return micros() - start;
//  }
 
//  unsigned long testTriangles() {
//    unsigned long start;
//    int           n, i, cx = tft.width()  / 2 - 1,
// 					   cy = tft.height() / 2 - 1;
 
//    tft.fillScreen(ILI9488_BLACK);
//    n     = min(cx, cy);
//    start = micros();
//    for(i=0; i<n; i+=5) {
// 	 tft.drawTriangle(
// 	   cx    , cy - i, // peak
// 	   cx - i, cy + i, // bottom left
// 	   cx + i, cy + i, // bottom right
// 	   tft.color565(0, 0, i));
//    }
 
//    return micros() - start;
//  }
 
//  unsigned long testFilledTriangles() {
//    unsigned long start, t = 0;
//    int           i, cx = tft.width()  / 2 - 1,
// 					cy = tft.height() / 2 - 1;
 
//    tft.fillScreen(ILI9488_BLACK);
//    start = micros();
//    for(i=min(cx,cy); i>10; i-=5) {
// 	 start = micros();
// 	 tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
// 	   tft.color565(0, i, i));
// 	 t += micros() - start;
// 	 tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
// 	   tft.color565(i, i, 0));
//    }
 
//    return t;
//  }
 
//  unsigned long testRoundRects() {
//    unsigned long start;
//    int           w, i, i2,
// 				 cx = tft.width()  / 2 - 1,
// 				 cy = tft.height() / 2 - 1;
 
//    tft.fillScreen(ILI9488_BLACK);
//    w     = min(tft.width(), tft.height());
//    start = micros();
//    for(i=0; i<w; i+=6) {
// 	 i2 = i / 2;
// 	 tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, 0, 0));
//    }
 
//    return micros() - start;
//  }
 
//  unsigned long testFilledRoundRects() {
//    unsigned long start;
//    int           i, i2,
// 				 cx = tft.width()  / 2 - 1,
// 				 cy = tft.height() / 2 - 1;
 
//    tft.fillScreen(ILI9488_BLACK);
//    start = micros();
//    for(i=min(tft.width(), tft.height()); i>20; i-=6) {
// 	 i2 = i / 2;
// 	 tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(0, i, 0));
//    }
 
//    return micros() - start;
//  }
 