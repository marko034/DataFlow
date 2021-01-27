/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 6      Example: 3      Name: Vectors
 * MaxFile name: Vectors
 * Summary:
 *    Streams a vector of integers to the dataflow engine and confirms that the
 *    returned stream contains the integers values doubled.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

int check(int vectorSize, int outValue, uint32_t *expectedVector)
{
	int status = 0;
	/*for (int i = 0; i < vectorSize * Vectors_vectorSize; i++) {
		if (outVector[i] != expectedVector[i]) {
			fprintf(stderr, "Error detected outVector[%d] != %d\n",
				outVector[i], expectedVector[i]);
			status = 1;
		}
	}*/
	if(outValue!=0){
	    status = 1;
	}
	return status;
}

void VectorsCPU(int32_t vectorSize, uint32_t *inVector, uint32_t *outVector)
{
	for (int i = 0; i < vectorSize * Vectors_vectorSize; i++) {
		outVector[i] = inVector[i] * 8;
	}
}

int main()
{
	const int vectorSize = Vectors_vectorSize;
	const int streamSize = 2;
	size_t sizeBytes = vectorSize * streamSize * sizeof(uint32_t);
	size_t sizeBytesRowColumn = vectorSize * sizeof(uint32_t);
	uint32_t *twoMatrix = malloc(sizeBytes);
	uint32_t *inVector1 = malloc(sizeBytesRowColumn);
	uint32_t *inVector2 = malloc(sizeBytesRowColumn);
	uint32_t *outVector = malloc(sizeBytesRowColumn);
	uint32_t outValue;
	uint32_t expectedValue;// = malloc(sizeBytes);
	
	

	for (int i = 0; i < vectorSize * streamSize; i++) {
		twoMatrix[i] = i;
	}
	
	for (int i = 0; i < vectorSize; i++) {
    		inVector1[i] = twoMatrix[i];
    }
    
    for (int i = 0; i < vectorSize; i++) {
    		inVector2[i] = twoMatrix[i*Math.sqrt(vectorSize)+vectorSize];
    }
	
	int sequence = 0;
	/*while(sequence < Math.sqrt(vectorSize)){
    	for (int i = 0; i < Math.sqrt(vectorSize); i++) {
    		inVector[i] = twoMatrix[i];
    	}
    	for (int i = 0; i < Math.sqrt(vectorSize); i++) {
    		inVector[i+Math.sqrt(vectorSize)] = twoMatrix[i*Math.sqrt(vectorSize)+vectorSize];
    	}
    	printf("Running DFE.\n");
	    
    	sequence++;
	}*/


    Vectors(streamSize, inVector1, invector2, outVector);

	for (int i = 0; i < vectorSize; i++) {
		outVector[i] = outVector[i];
	}

	//VectorsCPU(streamSize, inVector, outVector);

	//printf("Running DFE.\n");
	//Vectors(streamSize, inVector, expectedVector);

    int status = 1;
	/*int status = check(streamSize, outValue, expectedVector);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");*/

	return status;
}
