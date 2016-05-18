#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main() {







}

double convvel(double old, char from[10], char to[10]) {

	double new

	switch (from) {
		case "ft/s" :
			switch (to) {
				case "m/s" :
					new = old/3.280840;

				case "km/s" :
					new = old*1.09728;

				case "mph" :
					new = old/5280*3600;

				case "in/s" :
					new = old*12;

				case "km/h" :
					new = old;

				case "kts" :
					new = old;

				case "ft/min" :
					new = old;
				
			}
		case "m/s" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "km/s" :
					new = old;

				case "mph" :
					new = old;

				case "in/s" :
					new = old;

				case "km/h" :
					new = old;

				case "kts" :
					new = old;

				case "ft/min" :
					new = old;
				
			}
		case "km/s" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "m/s" :
					new = old;

				case "mph" :
					new = old;

				case "in/s" :
					new = old;

				case "km/h" :
					new = old;

				case "kts" :
					new = old;

				case "ft/min" :
					new = old;
				
			}
		case "mph" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "km/s" :
					new = old;

				case "m/s" :
					new = old;

				case "in/s" :
					new = old;

				case "km/h" :
					new = old;

				case "kts" :
					new = old;

				case "ft/min" :
					new = old;
				
			}
		case "in/s" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "km/s" :
					new = old;

				case "mph" :
					new = old;

				case "m/s" :
					new = old;

				case "km/h" :
					new = old;

				case "kts" :
					new = old;

				case "ft/min" :
					new = old;
				
			}

		case "km/h" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "km/s" :
					new = old;

				case "mph" :
					new = old;

				case "in/s" :
					new = old;

				case "km/s" :
					new = old;

				case "kts" :
					new = old;

				case "ft/min" :
					new = old;
				
			}

		case "kts" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "km/s" :
					new = old;

				case "mph" :
					new = old;

				case "in/s" :
					new = old;

				case "km/h" :
					new = old;

				case "m/s" :
					new = old;

				case "ft/min" :
					new = old;
				
			}

		case "ft/min" :
			switch (to) {
				case "ft/s" :
					new = old;

				case "km/s" :
					new = old;

				case "mph" :
					new = old;

				case "in/s" :
					new = old;

				case "km/h" :
					new = old;

				case "kts" :
					new = old;

				case "m/s" :
					new = old;
				
			}
	}

	return new;
}


