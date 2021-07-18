#include<stdio.h>

int main()
{
    unsigned char ch;
    int key_length = 1; 
    int cnt1 = 0;
    int ascii[300] = {0}; // save results of counting letters
    double freq_list[10] = {0}; 
    int freq_order[10] = {1,2,3,4,5,6,7,8,9,10};
    int key[10] = {0};  // ' '
    int key2[10] = {0}; // 'e'
    int key3[10] = {0}; // 't'
    int key4[10] = {0}; // 'a'
    int key5[10] = {0}; // 'i'
    int key6[10] = {0}; // 'n'
    int key7[10] = {0}; // 'o'
    int key8[10] = {0}; // 's'
    int final_key[10] = {0}; // save key value
    double frequency[8] = {0}; // save frequency of each case
    FILE *fpIn, *fpOut;
    fpIn = fopen("hw1_input.txt", "r");
    fpOut = fopen("hw1_output.txt", "wb");
    
    //finding frequency of each key length
    for(int i=1; i<11; i++) 
    {
        double num = 0;
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%i == 0)
            {
                ascii[ch] ++;
                num ++;
            }
        }

        double freq = 0;
        for(int k=0; k<300; k++)
        {
            if(ascii[k] != 0)
            {
                freq += ((ascii[k]/num)*(ascii[k]/num));
            }
        }


        freq_list[i-1] = freq;

        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }

        fpIn = fopen("hw1_input.txt", "r");
    }

    //frequency order, index order following this
    double tmp;
    int tmp2;
    for(int x=0; x<9; x++)
    {
        for(int y=x+1; y<10; y++)
        {
            if(freq_list[x] < freq_list[y])
            {
                //frequency order > freq_list
                tmp=freq_list[y];
                freq_list[y]=freq_list[x];
                freq_list[x]=tmp;

                //key length > freq_order
                tmp2=freq_order[y];
                freq_order[y]=freq_order[x];
                freq_order[x]=tmp2;
            }
        }
    }

    //caculate gdc of two index which has largest frequency
    int v1=freq_order[0], v2=freq_order[1];
    int can;
    if((freq_list[0]-freq_list[1]) > 0.01)
    {
        can = v1;
    }
    else
    {
        int min = (v1<v2)?v1:v2;
        for(int x=1; x<=min; x++)
        {
            if(v1%x==0 && v2%x==0)
            {
                can=x;
            }
        }
        if(can==1 && v1 != 1)
        {
            can = v1;
        }
    }   

    //find multiple of can (smaller than 11)
    int x;
    for(x=1; x<11; x++)
    {
        if(can*x > 10)
        {
            break;
        }
    }
    can = can*(x-1);

    key_length = can;

    //finding key value _ assume most frequent letter : space
    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key value
        int key_value = ' '^max;
        key[cnt1] = key_value;

        //initialization
        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key[k] != key[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //check frequency of lowercase letters
    double num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    double freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[0] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    //finding key value _ assume most frequent letter : 'e'
     fpIn = fopen("hw1_input.txt", "r");
     key_length = can;
     cnt1 = 0;

     for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 'e'^max;
        key2[cnt1] = key_value;

        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key2[k] != key2[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key2 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[1] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    //finding key value _ assume most frequent letter : 't'
    fpIn = fopen("hw1_input.txt", "r");
    key_length = can;
    cnt1 = 0;

    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 't'^max;
        key3[cnt1] = key_value;

        //initialization
        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key3[k] != key3[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key3 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[2] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }
    //finding key value _ assume most frequent letter : 'a'
    fpIn = fopen("hw1_input.txt", "r");
    key_length = can;
    cnt1 = 0;

    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 'a'^max;
        key4[cnt1] = key_value;

        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key4[k] != key4[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key4 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[3] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    fpIn = fopen("hw1_input.txt", "r");
    key_length = can;
    cnt1 = 0;

    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 'i'^max;
        key5[cnt1] = key_value;

        //initialization
        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key5[k] != key5[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key5 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[4] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    fpIn = fopen("hw1_input.txt", "r");
    key_length = can;
    cnt1 = 0;

    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 'n'^max;
        key6[cnt1] = key_value;

        //initialization
        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key6[k] != key6[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key6 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[5] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    fpIn = fopen("hw1_input.txt", "r");
    key_length = can;
    cnt1 = 0;

    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 'o'^max;
        key7[cnt1] = key_value;

        //initialization
        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key7[k] != key7[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }

    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key7 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[6] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    fpIn = fopen("hw1_input.txt", "r");
    key_length = can;
    cnt1 = 0;

    for(int i=0; i<can; i++)
    {
        for(int j=0; fscanf(fpIn,"%c",&ch)!= EOF; j++) 
        {
            if(j%can == i)
            {
                ascii[ch]++;    
            }
        }

        //find most frequent letter
        int max = 0;
        for(int j=0; j<300; j++)
        {
            if(ascii[j] > ascii[max])
            {
                max = j;
            }
        }

        //calculate key_value
        int key_value = 's'^max;
        key8[cnt1] = key_value;

        //initialization
        for(int k=0;k<300;k++)
        {
            ascii[k] = 0;
        }
        fpIn = fopen("hw1_input.txt", "r");
        cnt1 ++;
    }

    //find final key length
    for(int i=1; i<can; i++)
    {
        int check = 0;
        for(int k=0;k<10;k++)
        {
            if((key8[k] != key8[k+i]) && (k+i < can))
            {
                check ++;
            }
        }

        if(check == 0)
        {
            key_length = i;
            break;
        }
    }
    
    //count letters
    num = 0;
    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= key8 [ i % key_length] ;
        if(i%key_length == 0)
        {
            ascii[ch] ++;
            num++;
        }
    }

    //calculate frequency of lowercase letters
    freq = 0;
    for(int k=97; k<123; k++)
    {
        if(ascii[k] != 0)
        {
            freq += ((ascii[k]/num)*(ascii[k]/num));
        }
    }
    freq += ((ascii[32]/num)*(ascii[32]/num));
    frequency[7] = freq;

    //initialization
    for(int k=0;k<300;k++)
    {
        ascii[k] = 0;
    }

    //find max frequency
    int max = 0;
    for(int i=0; i<8; i++)
    {
        if(frequency[i] > frequency[max])
        {
            max = i;
        }
    }

    //put key to final_key
    if(max == 0)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key[i];
        }
    }

    else if(max == 1)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key2[i];
        }
    }

    else if(max == 2)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key3[i];
        }
    }

    else if(max == 3)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key4[i];
        }
    }

    else if(max == 4)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key5[i];
        }
    }

    else if(max == 5)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key6[i];
        }
    }

    else if(max == 6)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key7[i];
        }
    }

    else if(max == 7)
    {
        for(int i=0;i<10;i++)
        {
            final_key[i] = key8[i];
        }
    }

    //save to output file
    fpIn = fopen("hw1_input.txt", "r");
    for(int i=0; i<key_length; i++)
    {
        int tmp;
        int x=1,y;
        char hex[5];
        int q = final_key[i];
        while(q!=0) {
            int tmp = q % 16;
            if( tmp < 10)
            {
                tmp =tmp + 48; 
            }
            else
            {
                tmp = tmp + 55;
            }
            hex[x++]= tmp;
            q = q / 16;
        }
        ch = '0';
        fwrite(&ch, sizeof(ch), 1, fpOut);
        ch = 'x';
        fwrite(&ch, sizeof(ch), 1, fpOut);
        if(x == 2)
        {
            ch = '0';
            fwrite(&ch, sizeof(ch), 1, fpOut);
        }
        for (y = x-1 ;y> 0;y--)
        {
            ch = hex[y];
            fwrite(&ch, sizeof(ch), 1, fpOut);
        }
        ch = ' ';
        fwrite(&ch, sizeof(ch), 1, fpOut);
    }

    ch = '\n';
    fwrite(&ch, sizeof(ch), 1, fpOut);

    for ( int i = 0 ; fscanf( fpIn , "%c" , &ch ) != EOF; ++i ) {
        ch ^= final_key [ i % key_length] ;
        fwrite(&ch , sizeof(ch) , 1 , fpOut ) ;
    }

    return 0;
}
