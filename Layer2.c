#include <math.h>
#define SIGMOID(x) (1.7159*tanh(0.66666667*x))
#define IMGWIDTH 29
#define IMGHEIGHT 29

void calculateLayer2(float Layer1_Neurons_CPU[IMGWIDTH*IMGHEIGHT], float Layer1_Weights_CPU[(5*5+1)*6], float Layer2_Neurons_CPU[6*13*13]){
#pragma HLS INTERFACE s_axilite port=return bundle=A
#pragma HLS INTERFACE s_axilite port=Layer1_Neurons_CPU bundle=A
#pragma HLS INTERFACE s_axilite port=Layer1_Weights_CPU bundle=A
#pragma HLS INTERFACE s_axilite port=Layer2_Neurons_CPU bundle=A
		float somme;
	int i,j,k,m,n;
	for(i=0;i<6;i++)
		for(j=0;j<13;j++)
			for(k=0;k<13;k++){
				somme = Layer1_Weights_CPU[26*i];
				for(m=0;m<5;m++)
					for(n=0;n<5;n++)
						somme += Layer1_Weights_CPU[26*i+5*m+n+1] * Layer1_Neurons_CPU[29*(m+2*j)+n+2*k];
				Layer2_Neurons_CPU[13*13*i+13*j+k] = (float) SIGMOID(somme);
			}
}
