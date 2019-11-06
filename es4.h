 int es4stringPrefixes() {          // funziona solo se non ci sono spazi
     char string[50];
     scanf("%[^\n]", &string);      // cin >> string;
     int len=strlen(string);
     for(int i=len; i>0; i--) {
         printf("%.*s\n", i, string);
     }
     return 0;
 }