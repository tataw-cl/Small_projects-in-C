//C programming implementation of the ceasar cipher encryption algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Ceasar_encrypt(char message[], int key){
    char cha;
    int i=0;
   while (message[i]!='\0')
   {
    cha=message[i];
    if(cha>='a'&&cha<='z'){
        cha=cha+key;
        if (cha>'z')
        {
            cha=cha-'z'+'a'-1;
        }
        message[i]=cha;
    }
    else if (cha>='A'&&cha<='Z')
    {
        cha=cha+key;
        if(cha>'Z'){
            cha=cha-'Z'+'A'-1;
        }
        message[i]=cha;
    }
    i++;
   }
}

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