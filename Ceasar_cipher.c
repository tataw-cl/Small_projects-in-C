//C programming implementation of the ceasar cipher encryption algorithm
#include <stdio.h>
#include <stdlib.h>
void Ceasar_encrypt(char message[], int key){//function which will encrypt the message
    char cha; //variable to store the characters
    int i=0;
   while (message[i]!='\0') //loop to iterate through the message contents
   {
    cha=message[i]; //initialize the cha to the ith character of the message
    if(cha>='a'&&cha<='z'){//check if the character is a lowercase letter
        cha=cha+key;//add the key to the character
        if (cha>'z')//check if the new value of character is greater than z
        {
            cha=cha-'z'+'a'-1;//wrap around the character
        }
        message[i]=cha;//return the value after encryption
    }
    else if (cha>='A'&&cha<='Z')//check if the character is an uppercase letter
    {
        cha=cha+key;
        if(cha>'Z'){
            cha=cha-'Z'+'A'-1;
        }
        message[i]=cha;
    }
    i++;//increment to next character
   }
}

//main function to test the encryption
int main(){
    char mess[100];
    int key;
    printf("Enter the messsage for encryption: ");
    fgets(mess,sizeof(mess),stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    Ceasar_encrypt(mess,key);
    printf("Encrypted messasge is: %s\n", mess);

    return 0;
}