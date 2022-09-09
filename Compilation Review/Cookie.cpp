


#include "BoardObjectH.h"
#include "CookieH.h"

int PrizeValues[]={10,20,30,40};
//! Defines what happens when a player touches the object
void Cookie :: touch ()
		{ switch (status)
		  { case VISIBLE : if (color1==get_Color() )
			            set_color(color2);
			          else
			             set_color(color1);
                                   break;
		    case  EATEN :
		    case  EXPIRED :
			             set_color(BACKGROUND);
		  }
		}
//Get the value of the cookie
int Cookie :: get_value ()
	{return PrizeValues[valueIndex]; }

