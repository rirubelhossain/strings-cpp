\*==================================================*/
void SUNDAY(char *text, char *patt){
size_t temp[256];
size_t *shift = temp;
size_t i, patt_size = strlen(patt), text_size = strlen(text);
cout << "size : " << patt_size << endl;
for( i=0; i < 256; i++ ) *(shift+i) = patt_size+1;
for( i=0; i < patt_size; i++ )
*(shift+unsigned char(*(patt+i))) = patt_size-i;
//shift['s']=6��,shitf['e']=5�Դ�����
size_t limit = text_size-patt_size+1;
for( i=0; i < limit; i += shift[ text[i+patt_size] ] )
if( text[i] == *patt ){
char *match_text = text+i+1;
size_t match_size = 1;
do{// �������ƥ���λ��
if( match_size == patt_size ) cout << "the NO. is " << i << endl;
}while( (*match_text++) == patt[match_size++] );
}
cout << endl;
}
int main(void){
char *text = new char[100];
text = "substring searching algorithm search";
char *patt = new char[10];
patt = "search";
SUNDAY(text, patt);
return 0;
}
/*
size : 6
the NO. is 10
the NO. is 30
*/