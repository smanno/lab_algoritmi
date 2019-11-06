int es3stringSuffixes() {
    char string[50];                // devo dargli o una grandezza o il contenuto
    scanf("%[^\n]", &string);       // "%s" si ferma agli spazi; "%[^\n]" legge tutto eccetto il capolinea \n
    for(int i=0; string[i]!='\0'; i++) {
        cout << &string[i] << endl;
    }
    return 0;
}