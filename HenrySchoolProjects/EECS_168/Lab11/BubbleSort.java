/* -----------------------------------------------------------------------------
 *
 * File Name:  BubbleSort.java
 * Author: Henry Nguyen h724n828@ku.edu
 * Assignment:   EECS-168/169 Lab 11
 * Description:  Class that performs either ascending order or descending order sorting
 * Date: 12-2-13
 *
 ---------------------------------------------------------------------------- */

public class BubbleSort
{
	
	public void ascendingSort(int[] array)
	{
		int temp;
		int arraySize = array.length;
		
		for(int i=0; i<arraySize-1;i++)
		{
			for(int j=0; j<arraySize-1;j++)
			{
				//Swaps element position if conditions met for 
				//ascending order
				if(array[j] > array[j+1])
				{
					temp=array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
	
	public void descendingSort(int[] array)
	{
		int temp;
		int arraySize = array.length;
		
		for(int i=0; i<arraySize-1;i++)
		{
			for(int j=0; j<arraySize-1;j++)
			{
				//Swaps element position if conditions met for
				//descending order
				if(array[j] < array[j+1])
				{
					temp=array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
			}
		}
	}
	
}
