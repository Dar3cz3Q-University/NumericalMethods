#include "Horner.h"
#include "HornerNewton.h"
#include "WspNewtona.h"
#include "Lagrange.h"
#include "Newton.h"
#include "GaussCrout.h"
#include "Doolittle.h"
#include "TrapezeSimpson.h"
#include "GaussLegendre.h"
#include "GramSchmidtVector.h"
#include "GramSchmidtFunction.h"
#include "Approximation.h"
#include "EulerRungeKutta.h"
#include "GaussPlane.h"

int main(int argc, int** argv) 
{
	std::cout.precision(10);

	check_surface_integral();
}