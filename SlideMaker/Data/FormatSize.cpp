#include "FormatSize.hpp"

#include <unordered_map>
#include <string>

std::pair<std::string, std::pair<double, double> > FormatSize::createFormatSize(const std::string& formatName) {
    ///NOTE: PRETEND THIS IF ELSE IS A MAP
    if (formatName == "A0") return {"A0", {84.1, 118.9}};
    else if (formatName == "A1") return {"A1", {59.4, 84.1}};
    else if (formatName == "A2") return {"A2", {42, 59.4}};
    else if (formatName == "A3") return {"A3", {29.7, 42}};
    else if (formatName == "A4") return {"A4", {21, 29.7}};
    else if (formatName == "A5") return {"A5", {14.85, 21}};
    else if (formatName == "A6") return {"A6", {10.5, 14.85}};
    else if (formatName == "A7") return {"A7", {7.4, 10.5}};
    else if (formatName == "A8") return {"A8", {5.2, 7.4}};
    else if (formatName == "A9") return {"A9", {3.7, 5.2}};
    else if (formatName == "A10") return {"A10", {2.6, 3.7}};
}

/*
 A0	 841 x 1189 mm	 84.1 x 118.9 cm  33.1 x 46.8 inches
 A1	 594 x 841 mm	 59.4 x 84.1 cm	  23.4 x 33.1 inches
 A2	 420 x 594 mm	 42 x 59.4 cm	  16.5 x 23.4 inches
 A3	 297 x 420 mm	 29.7 x 42 cm	  11.7 x 16.5 inches
 A4	 210 x 297 mm	 21 x 29.7 cm	  8.3 x 11.7 inches
 A5	 148.5 x 210 mm	 14.85 x 21cm	  5.8 x 8.3 inches
 A6	 105 x 148.5 mm	 10.5 x 14.85 cm  4.1 x 5.8 inches
 A7	 74 x 105 mm	 7.4 x 10.5 cm	  2.9 x 4.1 inches
 A8	 52 x 74 mm	     5.2 x 7.4 cm	  2.0 x 2.9 inches
 A9	 37 x 52 mm	     3.7 x 5.2 cm	  1.5 x 2.0 inches
 A10 26 x 37 mm	     2.6 x 3.7 cm	  1.0 x 1.5 inches
*/
