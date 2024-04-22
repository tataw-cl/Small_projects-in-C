#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//Function to encrypt the message using vigenere
void vigenere_encrypt(char message[], char key[]){
    int messageLenght=strlen(message);
    int keylength=strlen(key);
    int i, j;
    for ( i = 0, j=0; i < messageLenght; i++,j++)
    {
        if (j==keylength)
        {
            j=0;
        }
        //Convert the characters to uppercase.
        message[i]=toupper(message[i]);
        key[j]=toupper(key[j]);
        //Encrypt the character
        if (message[i]>='A'&& message[i]<='Z')
        {
            // Applying the vigenere encryption cipher algo     for mular
            message[i]=((message[i]+key[j]%26)+'A');//return the encrypted message
               }
    }
    
}

void vigenere_Decrypt(char message[], char key[]){
    int messageLenght=strlen(message);
    int keylength=strlen(key);
    int i, j;
    for ( i = 0, j=0; i < messageLenght; i++,j++)
    {
        if (j==keylength)
        {
            j=0;
        }
        //Convert the characters to uppercase.
        message[i]=toupper(message[i]);
        key[j]=toupper(key[j]);
        //Encrypt the character
        if (message[i]>='A'&& message[i]<='Z')
        {
            // Applying the vigenere encryption cipher algo formular
            message[i]=(((message[i]-key[j]+26)%26)+'A');
               }
    }
}

int main(){
    char mess[100];
    char key[100];
    printf("Enter the message for encryption\n");
    fgets(mess,sizeof(mess),stdin);
    printf("Enter the key for encryption\n");
    fgets(key,sizeof(key),stdin);

    vigenere_encrypt(mess,key);
    printf("The encrypted message is: %s\n",mess);
    vigenere_Decrypt(mess,key);
    printf("The decrypted message is: %s\n",mess);
return 0;
}
