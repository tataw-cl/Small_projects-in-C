//C program to implement Columnar Transposition Cipher with the use of numerical keys
//Note:keys are supposed to be at least the squareroots of the number of character in the message
#include <stdio.h>
#include <string.h>
//Encipher function
char columnarTranspositionEncipher(char message[], int key) {
        //Function to get the length of key
        int getlength(int num){
    int length = 0;
    while(num != 0) {
        num /= 10;
        length++;
    }
    return length;
}
//return the value to keylen variable
int keylen = getlength(key);
//-----------------------------------------------------------------------------
    //initialize ciphertext array of size keylen
    char cipherText[keylen][keylen];
     //Array to keep the order of columns(key) for execution
     int keyODR[keylen]; // The maximum size will be the highest value of the key
     //code block to seperate the individual digits of the key
     int k = 0;
      int digit;
     while (key > 0) {
          digit= key % 10;
         keyODR[k] = digit;//return the digits to array keyODR[]
         key = key / 10;
         k++;
     }
//------------------------------------------------------------------------------
     
         //get message lenght
        int messageLength = strlen(message);
        //replace all spaces with underscore character 
     for(int i=0;i<messageLength;i++){
        if (message[i]==' ')
        {
            message[i]='_';
        }
        
     }
//---------------------------------------------------------------------------------     
    //code block to input the user message into cipher array
     int count=0;//keep track of end of message to include redundant characters
    for (int i = 0; i < keylen; i++) {
    for (int j = 0; j < keylen; j++) {
        if (count < messageLength-1) {
            cipherText[i][j] = message[count];
            count++;
        } else {
            cipherText[i][j] = '~'; // Fill remaining spaces with '~' or any other character
        }
        
    }
}
//-------------------------------------------------------------------------------
 //code block to return encrypted text
    int index=0;
    for ( int j=keylen-1;j>=0;j--)
    {
        for (int i = 0; i < keylen; i++)
        {
        message[index]=cipherText[i][keyODR[j]];
        index+=1;
        }
    }
    message[index+1]='\0';
}

//end encipher--------------------------------------------------------------------------------------------------


//Function to decipher the text
  void columnarTranspositionDecipher(char cipherText[], int key) {
//------------------------------------------------------------------------
     //Function to get the length of key
     int getlength(int num){
    int length = 0;
    while(num != 0) {
        num /= 10;
        length++;
    }
    return length;
}
    int keylen=getlength(key);//store value in keylen variable
//----------------------------------------------------------------------------
     //code block to seperate the individual digits of key
     int k = 0;
     int count=0;
     int digit;
     //Array to keep the order of key of size keylen
    int keyODR[keylen];
     while (key > 0) {
          digit= key % 10;
         keyODR[k] = digit;
         key = key / 10;
         k++;
     } //will store digits in reverse order(i.e, last digit in first index[0] and vice versa) inside array keyODR
//-------------------------------------------------------------------------------
    //Get length of ciphertext
    int cipherTextLength = strlen(cipherText);
    //Pass ciphertext into decipherArray for deciphering
     char decipherArray[keylen][keylen];
     for (int i = keylen-1; i >=0; i--)
     {
        for (int j = 0; j < keylen; j++)
        {
            if (count<cipherTextLength)
            {
                //pass characters in coorect order according to key order (keyODR array values)
                decipherArray[j][keyODR[i]]=cipherText[count];
                count++;
            }
        }
     }
//-----------------------------------------------------------------------------------
    //return deciphered message
    int index=0;
    for (int i = 0; i < keylen; i++)
    {
        for (int j = 0; j < keylen; j++)
        {
            cipherText[index]=decipherArray[i][j];
            index++;
        }
    }
     cipherText[index+1]='\0';
//-----------------------------------------------------------------------------------
//replace underscores('_') with space(' ')
     for (int i = 0; i < cipherTextLength; i++)
     {
         if (cipherText[i]=='_')
         {
             cipherText[i]=' ';
         }
     }
//----------------------------------------------------------------------------------
//replace '~' with null value character to indicate end of string
     for (int i = 0; i < cipherTextLength; i++)
     {
         if (cipherText[i]=='~')
         {
             cipherText[i]='\0';
         }
     }

  }
//end decipher-------------------------------------------------------------------------------------------------------
int main() {
     char cipherText[100];
     int key;
      printf("\n\nWelcome to the C language implementation of columnar cipher.\nNote:The number of digits in your key should be at least the square of the number of characters you plan on entering\n");
     printf("Enter the message: ");
     printf("\n------------------------------------------------\n");
     fgets(cipherText, sizeof(cipherText), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);
     printf("\n");

      columnarTranspositionEncipher(cipherText, key);
      printf("Cipher Text: %s\n", cipherText);
    printf("--------------------------------------------------\n");
    columnarTranspositionDecipher(cipherText, key);
    printf("Deciphered message: %s\n",cipherText);
       return 0;
}