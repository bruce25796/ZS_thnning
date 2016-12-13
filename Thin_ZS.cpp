#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <Windows.h>

#include "dbg.h"

int  P268 ( unsigned char  *image_in 
							,  int imgWD
							,  int imgHI 
							,  int  x
							,  int  y
						  )

{
	const int  BackGND = 0;
	const int  ForeGND = 255;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int  P2, P6, P8;
	int count;
	

	count = 0;

	
	(image_in [  (y-1) *X_SIZE + (x)    ] == ForeGND ) ? P2 =1   :P2 =0 ;
	(image_in [  (y+1) *X_SIZE + (x)    ] == ForeGND ) ? P6 =1   :P6 =0 ;
	(image_in [  (y  ) *X_SIZE + (x-1)  ] == ForeGND ) ? P8 =1   :P8 =0 ;
	
	count =  P2*P6*P8;

    return count;
}

int  P248( unsigned char  *image_in 
							,  int imgWD
							,  int imgHI 
							,  int  x
							,  int  y
						  )
{
	const int  BackGND = 0;
	const int  ForeGND = 255;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int  P2, P4, P8;
	int count;
	

	count = 0;

	(image_in [  (y-1) *X_SIZE + (x)    ] == ForeGND ) ? P2 =1   :P2 =0 ;
	(image_in [  (y  ) *X_SIZE + (x+1)  ] == ForeGND ) ? P4 =1   :P4 =0 ;
	(image_in [  (y  ) *X_SIZE + (x-1)  ] == ForeGND ) ? P8 =1   :P8 =0 ;
	
	count = P2*P4*P8;

    return count;


}


int  P468 ( unsigned char  *image_in 
							,  int imgWD
							,  int imgHI 
							,  int  x
							,  int  y
						  )

{
	const int  BackGND = 0;
	const int  ForeGND = 255;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int  P4, P6, P8;
	int count;
	

	count = 0;

	
	(image_in [  (y  ) *X_SIZE + (x+1)  ] == ForeGND ) ? P4 =1   :P4 =0 ;
	(image_in [  (y+1) *X_SIZE + (x)    ] == ForeGND ) ? P6 =1   :P6 =0 ;
	(image_in [  (y  ) *X_SIZE + (x-1)  ] == ForeGND ) ? P8 =1   :P8 =0 ;
	
	count =  P4*P6*P8;

    return count;
}


int  P246 ( unsigned char  *image_in 
							,  int imgWD
							,  int imgHI 
							,  int  x
							,  int  y
						  )

{
	const int  BackGND = 0;
	const int  ForeGND = 255;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int  P2, P4, P6;
	int count;
	

	count = 0;

	(image_in [  (y-1) *X_SIZE + (x)    ] == ForeGND ) ? P2 =1   :P2 =0 ;
	(image_in [  (y  ) *X_SIZE + (x+1)  ] == ForeGND ) ? P4 =1   :P4 =0 ;
	(image_in [  (y+1) *X_SIZE + (x)    ] == ForeGND ) ? P6 =1   :P6 =0 ;
	
	count = P2*P4*P6;

    return count;
}




int  Num_Transition_Neighbors(  unsigned char  *image_in 
							,  int imgWD
							,  int imgHI 
							,  int  x
							,  int  y
						  )
{
	const int  BackGND = 0;
	const int  ForeGND = 255;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int count;

	count = 0;

	if (     ( image_in [  (y-1) *X_SIZE + (x)    ]  ==   BackGND   )
          && ( image_in [  (y-1) *X_SIZE + (x+1)  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 2, 3
	//
	if (     ( image_in [  (y-1) *X_SIZE + (x+1)  ]  ==   BackGND   )
          && ( image_in [  (y  ) *X_SIZE + (x+1)  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 3, 4
	if (     ( image_in [  (y  ) *X_SIZE + (x+1)  ]  ==   BackGND   )
          && ( image_in [  (y+1) *X_SIZE + (x+1)  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 4, 5
	if (     ( image_in [  (y+1) *X_SIZE + (x+1)  ]  ==   BackGND   )
          && ( image_in [  (y+1) *X_SIZE + (x  )  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 5, 6
	//---------------------
	if (     ( image_in [  (y+1) *X_SIZE + (x)    ]  ==   BackGND   )
          && ( image_in [  (y+1) *X_SIZE + (x-1)  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 6, 7
	//
	if (     ( image_in [ (y+1) *X_SIZE + (x-1)  ]  ==   BackGND   )
          && ( image_in [ (y  ) *X_SIZE + (x-1)  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 7, 8
	if (     ( image_in [  (y  ) *X_SIZE + (x-1)  ]  ==   BackGND   )
          && ( image_in [  (y-1) *X_SIZE + (x-1)  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 8, 9
	if (     ( image_in [  (y-1) *X_SIZE + (x-1)  ]  ==   BackGND   )
          && ( image_in [  (y-1) *X_SIZE + (x  )  ]  ==   ForeGND   )
	   )
	{
		count++;
	}  // 9, 2


	return count;
	//
}
int  Num_NonZero_Neighbors(  unsigned char  *image_in 
							,  int imgWD
							,  int imgHI 
							,  int  x
							,  int  y
						  )
{
	
	const int  BackGND = 0;
	const int  ForeGND = 255;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int count;


	count = 0;
	if ( image_in [  (y-1) *X_SIZE + (x-1)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y-1) *X_SIZE + (x)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y-1) *X_SIZE + (x+1)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y) *X_SIZE + (x-1)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y) *X_SIZE + (x+1)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y+1) *X_SIZE + (x-1)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y+1) *X_SIZE + (x)  ]  ==  ForeGND   )
	{
		count++;
	}
	if ( image_in [  (y+1) *X_SIZE + (x+1)  ]  ==  ForeGND   )
	{
		count++;
	}

	return count;
}


void ThinningZS ( 
				 HDC hdc, 
				unsigned char  *image_in   // image in & out
				,  int imgWD
				,  int imgHI
			    )
{
	int  i, j, k, l;
	int   Np, Tp;

	const int  BackGND = 0;
	const int  ForeGND = 255;
	const int  DeletTION = 1;
	const int  DeletTION_NOT = 0;
	int  count = 0;

	int  X_SIZE =   imgWD;
	int  Y_SIZE =   imgHI;
	int  p246, p468, p248, p268;

	unsigned char   *image_out	= (unsigned char *) HeapAlloc(GetProcessHeap(), 0, X_SIZE*Y_SIZE*sizeof( unsigned char) );
	memset( image_out, 0x00, sizeof(unsigned char) * X_SIZE * Y_SIZE );



   for (i=0 ; i< X_SIZE; i++) // Up , down border
   {
	   j = 0;
	   image_in[  j *X_SIZE + i  ] = BackGND;        

	   j = Y_SIZE-1;
	   image_in[  j *X_SIZE + i  ] = BackGND;
   }

   for (j=0; j< Y_SIZE; j++) // left, right  border
   {
	   i = 0;
	   image_in[  j *X_SIZE + i  ] = BackGND;  

	   i = X_SIZE-1;
	   image_in[  j *X_SIZE + i  ] = BackGND;
   }
   //------------------------------------

   double TpArray[9];
   memset( TpArray, 0x00,sizeof(int) * 9 );



//for (k=0 ; k <10; k++)
do 
{
	k = 0;
	count = 0;

	for (j= 1; j<= imgHI-2; j++)
	 for (i= 1; i<= imgWD-2; i++)
	 {
         if   (image_in[  j *X_SIZE + i  ] ==  ForeGND) 
		 {
			 Np = Num_NonZero_Neighbors(      image_in ,  imgWD, imgHI,  i,  j	);
			 Tp = Num_Transition_Neighbors(   image_in ,   imgWD, imgHI,  i,  j  );
				

	//TpArray[ Tp ]=  TpArray[ Tp ] + 1.0;


			 p246 = P246 ( image_in,  imgWD, imgHI,  i,  j );
			 p468 = P468 ( image_in,  imgWD, imgHI,  i,  j );

			 if ( ( Np >=2 ) && ( Np <= 6)
				  && ( Tp ==1)
				  && ( p246 == 0) 
				  && ( p468 == 0)
				  )
			 {
				 image_out[  j *X_SIZE + i ] =  DeletTION ;// for deletion
				 count ++;
			 }
		 }//-------

	 }
	 for (j= 1; j<= imgHI-2; j++)
	 for (i= 1; i<= imgWD-2; i++)
	 {
		 if (image_out[  j *X_SIZE + i ] ==  DeletTION ) {
		   image_in[  j *X_SIZE + i  ]  =  BackGND;
		   image_out[  j *X_SIZE + i ] =    DeletTION_NOT;

		   // SetPixel ( hdc, i, j, RGB( 0, 0, 0 ) );           
		 }
	 }
	 memset( image_out, 0x00, sizeof(unsigned char) * X_SIZE * Y_SIZE );
	 ///----- iteration 1


	 for (j= 1; j<= imgHI-2; j++)
	 for (i= 1; i<= imgWD-2; i++)
	 {
         if   (image_in[  j *X_SIZE + i  ] ==  ForeGND) 
		 {
			 Np = Num_NonZero_Neighbors(      image_in ,  imgWD, imgHI,  i,  j	);
			 Tp = Num_Transition_Neighbors(   image_in ,   imgWD, imgHI,  i,  j  );
						
			 p248 = P248 ( image_in,  imgWD, imgHI,  i,  j );
			 p268 = P268 ( image_in,  imgWD, imgHI,  i,  j );

			 if ( ( Np >=2 ) && ( Np <= 6)
				  && ( Tp ==1)
				  && ( p248 == 0) 
				  && ( p268 == 0)
				  )
			 {
				 image_out[  j *X_SIZE + i ] =  DeletTION ;// for deletion
				 count ++;
			 }
		 }//-------
	 }
	 for (j= 1; j<= imgHI-2; j++)
	 for (i= 1; i<= imgWD-2; i++)
	 {
		 if (image_out[  j *X_SIZE + i ] ==  DeletTION ) {
		   image_in[   j *X_SIZE + i   ]  =  BackGND;
		   image_out[  j *X_SIZE + i   ]  =  DeletTION_NOT;

		   // SetPixel ( hdc, i, j, RGB( 0, 0, 0 ) );  
		 }
	 }
	 memset( image_out, 0x00, sizeof(unsigned char) * X_SIZE * Y_SIZE );

}while (( k<= 10 ) && (count>0 ) );


    if (image_out) 
	{ 
		HeapFree (  GetProcessHeap(), 0, image_out	);  
		image_out = NULL; 
	}
}