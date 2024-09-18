
#include "sample_images.h"

TFT_eSPI tft = TFT_eSPI(); // Declare object "tft"

// TFT_eSprite spr = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object

void setup()
{
  Serial.begin(9600);

  // Initialise the TFT registers
  tft.init();

  // Clear the TFT screen to black
  tft.fillScreen(TFT_WHITE);

  tft.setSwapBytes(true);

  // Upload of battery icon high PNG image
  tft.pushImage(120, 10, 28, 42, batteryicon_high);

  // Signal stregth icon (5 signal bars)
  tft.fillRect(80, 40, 4, 10, TFT_BLACK); // lowest signal strength bar
  tft.fillRect(85, 35, 4, 15, TFT_BLACK);
  tft.fillRect(90, 30, 4, 20, TFT_BLACK);
  tft.fillRect(95, 25, 4, 25, TFT_BLACK);
  tft.fillRect(100, 20, 4, 30, TFT_BLACK); //  highest signal strength bar

  // Bed status images
  tft.pushImage(65, 70, 100, 60, bed_occupied); // standard bed icon no color

  // Status tracker boundary rectangulat frame---------------------------
  tft.drawRect(28, 198, 164, 24, TFT_BLACK);

  // Status tracker icon depending on time   (arcs clockwise progress bar design  )

  // First status ( for example:Time of sleep)----------------------------------------------------------------

  // uint16_t fg_color = TFT_CYAN;
  // uint16_t fg_color1 = TFT_DARKGREY;
  // uint16_t bg_color = TFT_WHITE; // This is the background colour used for smoothing (anti-aliasing)

  // uint16_t x = 120; // Position of centre of arc
  // uint16_t y = 180;

  // uint8_t radius = (50);                     // Outer arc radius
  // uint8_t thickness = (10);                  // Thickness
  // uint8_t inner_radius = radius - thickness; // Calculate inner radius (can be 0 for circle segment)

  // // 0 degrees is at 6 o'clock position
  // // // Arcs are drawn clockwise from start_angle to end_angle
  // // // Start angle can be greater than end angle, the arc will then be drawn through 0 degrees
  // uint16_t start_angle ; // Start angle must be in range 0 to 360
  // uint16_t end_angle ;   // End angle must be in range 0 to 360

  // bool roundEnds = 1; // true = smooth sides, false = no smooth sides

  // uint8_t first_time = 0;

  // // bool first_arc_done = false;   // Flag to track if the first arc is complete
  // // bool start_second_arc = false; // Flag to track if the second arc is complete

  // uint8_t counter = 30;

  // uint16_t current_fg_color;

  // while (true)
  // {
  //   delay(1000); // Wait for 1 second

  //   // end_angle = (end_angle == 360) ? 0: end_angle;
  //   // first_arc_done = (end_angle < 270) ? false : true;
  //   // uint16_t current_fg_color = first_arc_done ? fg_color : fg_color1; // Select color based on arc

  //   // // Update end_angle
  //   // // if (!first_arc_done) {
  //   // //   //  tft.drawSmoothArc(x, y, radius, inner_radius, start_angle, end_angle, current_fg_color, bg_color, roundEnds);
  //   // //   end_angle += 10;  // Increase end angle by 10 degrees
  //   // if (first_arc_done && !start_second_arc) {         // When end_angle reaches 270, mark the first arc as done
  //   //   start_second_arc = true;
  //   //   start_angle = end_angle + 10;  // New arc starts where the previous one ended
  //   //   end_angle = start_angle + 10;  // Start the new arc with a 10-degree segment

  //   // }
  //   // // else if (first_arc_done && end_angle < start_angle + 90) {
  //   // //   // Continue the second arc until 90 degrees after the start
  //   // //   end_angle += 10;
  //   // // }
  //   // end_angle += 10;  // Increase end angle by 10 degrees
    
  //   end_angle = counter * 6;

  //   if  (end_angle >= 180 && end_angle < 270 && first_time != 1)     // first startus arc 
  //   {
  //       first_time = 1;
  //       start_angle = counter * 6;
  //       current_fg_color = TFT_ORANGE;
  //   } 

  //   // if  (end_angle = 270 && first_time != 2)    // space between 1 and 2 status arc 
  //   // {
  //   //     first_time = 2;
  //   //     start_angle = counter * 6;
  //   //     current_fg_color = TFT_WHITE;
    // } 
    
  //    if (end_angle > 280 && first_time != 2)                         // second status arc 
  //   {
  //       first_time = 2;
  //       start_angle = counter * 6;
  //       current_fg_color = TFT_GREEN;
  //   }

  //   if (end_angle < 160 && first_time != 3)                          // third status arc 
  //   {
  //       first_time = 3;
  //       start_angle = counter * 6;
  //       current_fg_color = TFT_BLUE;
  //   }

   

    

  //   // Clear the previous arc segment
  //   tft.drawSmoothArc(x, y, radius, inner_radius, start_angle, end_angle + 1, current_fg_color, bg_color, roundEnds);
  //   if (counter < 60){
  //     counter++;
  //   }
  //   else counter = 0;
  // }
}

 // Status tracker icon depending on time   (rectangular progress bar design )-----------------------------------------------------------------------------------

uint16_t bg_color = TFT_WHITE;

uint16_t rect_height = 20;   // Height of the continuous line
uint16_t rect_y_start = 200;  // Y position for the line
uint16_t rect_max_width = 160; // Maximum width for the entire line

uint16_t rect1_width = 0;
uint16_t rect2_width = 0;
uint16_t rect3_width = 0;

uint8_t counter2 = 0;



void loop() {
  delay(1000); // Wait for 1 second

  // Clear the previous full width line
  tft.fillRect(30, rect_y_start, rect_max_width, rect_height, bg_color);

  // Increment the individual segment widths based on the counter
   if (counter2 <= 10) {
    rect1_width =  counter2 * 5 ;   
     tft.fillRect(30, rect_y_start, rect1_width, rect_height, TFT_ORANGE);           // First segment (orange)
   }

   if (counter2 > 10 && counter2 <= 20) {
    rect2_width = (counter2 - 10) * 5 ; // Second segment (green)
    tft.fillRect(30, rect_y_start, rect1_width, rect_height, TFT_ORANGE);   // Keep orange segment
    tft.fillRect(30 + rect1_width , rect_y_start, rect2_width, rect_height, TFT_GREEN);   // Second segment (green)
   }

   if (counter2 > 20) {
    rect3_width =  (counter2 - 20) * 5 ;         

  tft.fillRect(30, rect_y_start, rect1_width, rect_height, TFT_ORANGE);   // Keep orange segment
  tft.fillRect(30 + rect1_width , rect_y_start, rect2_width, rect_height, TFT_GREEN);   // Keep green segment 
  tft.fillRect(30 + rect1_width + rect2_width, rect_y_start, rect3_width, rect_height, TFT_BLUE);   // Third segment (blue)
   }
  // Increment the counter and reset after 90 to loop the process
  if (counter2 <= 30) {
    counter2++;
  } 
  else {
    counter2 = 0;
  }





  //Status tracker icon depending on time   (another arc clockwise progress bar design )-----------------------------------------------------------------------------------
  // tft.drawSmoothArc(x, y, radius, inner_radius, start_angle, end_angle, fg_color, bg_color, roundEnds);

  // Second status (for example: Time of being awake )----------------------------------------------------------------
  // uint16_t fg_color1 = TFT_DARKGREY;
  // uint16_t bg_color1 = TFT_WHITE;       // This is the background colour used for smoothing (anti-aliasing)

  // uint16_t x1 = 120;  // Position of centre of arc
  // uint16_t y1 = 180;

  // uint8_t radius1       = (40); // Outer arc radius
  // uint8_t thickness1    = (10);     // Thickness
  // uint8_t inner_radius1 = radius1 - thickness1;        // Calculate inner radius (can be 0 for circle segment)

  // 0 degrees is at 6 o'clock position
  // Arcs are drawn clockwise from start_angle to end_angle
  // Start angle can be greater than end angle, the arc will then be drawn through 0 degrees
  // uint16_t start_angle1 = 280; // Start angle must be in range 0 to 360
  // uint16_t end_angle1   = 40; // End angle must be in range 0 to 360

  // bool roundEnds1 = 1; // true = smooth sides, false = no smooth sides

  // tft.drawSmoothArc(x, y, radius, inner_radius, start_angle1, end_angle1, fg_color1, bg_color, roundEnds);

  // //Third status (for example: Time of sitting on bed )----------------------------------------------------------------
  // uint16_t fg_color2 = TFT_BLUE;
  // uint16_t bg_color2 = TFT_WHITE;       // This is the background colour used for smoothing (anti-aliasing)

  // uint16_t x2 = 120;  // Position of centre of arc
  // uint16_t y2 = 220;

  // uint8_t radius2       = (70); // Outer arc radius
  // uint8_t thickness2    = (10);     // Thickness
  // uint8_t inner_radius2 = radius2 - thickness2;        // Calculate inner radius (can be 0 for circle segment)

  //   // 0 degrees is at 6 o'clock position
  //   // Arcs are drawn clockwise from start_angle to end_angle
  //   // Start angle can be greater than end angle, the arc will then be drawn through 0 degrees
  // uint16_t start_angle2 = 50; // Start angle must be in range 0 to 360
  // uint16_t end_angle2   = 100; // End angle must be in range 0 to 360

  // bool roundEnds2 = 1; // true = smooth sides, false = no smooth sides

  // tft.drawSmoothArc(x2, y2, radius2, inner_radius2, start_angle2, end_angle2, fg_color2, bg_color2, roundEnds2);

  // Fourth status (for example: Time of moving in sleep )----------------------------------------------------------------
  //  uint16_t fg_color3 = TFT_ORANGE;
  //  uint16_t bg_color3 = TFT_WHITE;       // This is the background colour used for smoothing (anti-aliasing)

  // uint16_t x3 = 120;  // Position of centre of arc
  // uint16_t y3 = 220;

  // uint8_t radius3      = (70); // Outer arc radius
  // uint8_t thickness3    = (10);     // Thickness
  // uint8_t inner_radius3 = radius3 - thickness3;        // Calculate inner radius (can be 0 for circle segment)

  //   // 0 degrees is at 6 o'clock position
  //   // Arcs are drawn clockwise from start_angle to end_angle
  //   // Start angle can be greater than end angle, the arc will then be drawn through 0 degrees
  // uint16_t start_angle3 = 110; // Start angle must be in range 0 to 360
  // uint16_t end_angle3   = 170; // End angle must be in range 0 to 360

  // bool roundEnds3 = 1; // true = smooth sides, false = no smooth sides

  // tft.drawSmoothArc(x3, y3, radius3, inner_radius3, start_angle3, end_angle3, fg_color3, bg_color3, roundEnds3);





  // Dynamic change in battery icon
  //--------------------------------------------------------------
  delay(2000);

  tft.pushImage(120, 10, 28, 42, batteryicon_medium);

  delay(2000);

  tft.pushImage(120, 10, 28, 42, batteryicon_low);

  delay(2000);

  // Redisplay the first image in the same position
  tft.pushImage(120, 10, 28, 42, batteryicon_high);
  //--------------------------------------------------------

  // Dynamic change in signal strenth icon
  //----------------------------------------------------------------
  delay(2000);
  tft.fillRect(80, 40, 4, 10, TFT_BLACK); // lowest signal strength bar
  tft.fillRect(85, 35, 4, 15, TFT_WHITE);
  tft.fillRect(90, 30, 4, 20, TFT_WHITE);
  tft.fillRect(95, 25, 4, 25, TFT_WHITE);
  tft.fillRect(100, 20, 4, 30, TFT_WHITE); //  highest signal strength bar

  delay(2000);
  tft.fillRect(80, 40, 4, 10, TFT_BLACK); // lowest signal strength bar
  tft.fillRect(85, 35, 4, 15, TFT_BLACK);
  tft.fillRect(90, 30, 4, 20, TFT_WHITE);
  tft.fillRect(95, 25, 4, 25, TFT_WHITE);
  tft.fillRect(100, 20, 4, 30, TFT_WHITE); //  highest signal strength bar

  delay(2000);
  tft.fillRect(80, 40, 4, 10, TFT_BLACK); // lowest signal strength bar
  tft.fillRect(85, 35, 4, 15, TFT_BLACK);
  tft.fillRect(90, 30, 4, 20, TFT_BLACK);
  tft.fillRect(95, 25, 4, 25, TFT_WHITE);
  tft.fillRect(100, 20, 4, 30,TFT_WHITE); //  highest signal strength bar

  delay(2000);
  tft.fillRect(80, 40, 4, 10, TFT_BLACK); // lowest signal strength bar
  tft.fillRect(85, 35, 4, 15, TFT_BLACK);
  tft.fillRect(90, 30, 4, 20, TFT_BLACK);
  tft.fillRect(95, 25, 4, 25, TFT_BLACK);
  tft.fillRect(100, 20, 4, 30, TFT_WHITE); //  highest signal strength bar

  delay(2000);
  tft.fillRect(80, 40, 4, 10, TFT_BLACK); // lowest signal strength bar
  tft.fillRect(85, 35, 4, 15, TFT_BLACK);
  tft.fillRect(90, 30, 4, 20, TFT_BLACK);
  tft.fillRect(95, 25, 4, 25, TFT_BLACK);
  tft.fillRect(100, 20, 4, 30, TFT_BLACK); //  highest signal strength bar

  //----------------------------------------------------------------------------

  // Dynamic change in bed status including colour change

  delay(3000);
  tft.pushImage(65, 70, 100, 60, bed_occupied_green_); // standard bed icon (occupied- green)

  delay(3000);
  tft.pushImage(65, 70, 100, 60, bed_not_occupied); // standard bed icon(not occupied no color)

  delay(3000);
  tft.pushImage(65, 70, 100, 60, bed_not_occupied_red); // standard bed icon(not occupied - red)

  // Redisplay the first image in the same position
  delay(3000);
  tft.pushImage(65, 70, 100, 60, bed_occupied); // standard bed icon no color

  //--------------------------------------------------------------------------

  // Dynamic change in status live tracker icon depending on time.


}
