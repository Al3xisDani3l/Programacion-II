#include "FormulaGeneral.h"
#include <math.h>

double FormulaGeneral::CalculateX1() {

	
	

	return ((-b + sqrt((b * b) - (4 * a * c)) )/ (2 * a));

}

double FormulaGeneral::CalculateX2() {

	return ((-b - sqrt((b * b) - (4 * a * c))) / (2 * a));
}
