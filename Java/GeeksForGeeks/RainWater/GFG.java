/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		int testCount;
        int arraySize;
        int[] data;
        int[] maxLeft;
        int[] maxRight;

        Scanner in = new Scanner(System.in);
        testCount = in.nextInt();
        for(int i=0; i<testCount; i++)
        {
            arraySize = in.nextInt();
            data = new int[arraySize];
            maxLeft = new int[arraySize];
            maxRight = new int[arraySize];
            for(int j=0; j<arraySize; j++)
            {
                data[j] = in.nextInt();
            }
            int maxFromLeft = 0;
            int maxFromRight = 0;
            for(int j=0; j<arraySize; j++)
            {
                if(data[j]> maxFromLeft)
                {
                    maxFromLeft = data[j];
                }
                maxLeft[j] = maxFromLeft;

                if(data[arraySize-1-j]> maxFromRight)
                {
                    maxFromRight = data[arraySize-1-j];
                }
                maxRight[arraySize-1-j] = maxFromRight;
            }
            /*
            System.out.println(Arrays.toString(data));
            System.out.println(Arrays.toString(maxLeft));
            System.out.println(Arrays.toString(maxRight));
            */
            int waterSum = 0;
            for(int j=0; j<arraySize; j++)
            {
                waterSum+= (maxLeft[j] < maxRight[j] ? maxLeft[j] : maxRight[j] ) - data[j];
            }
            System.out.println(waterSum);
        }
	}
}