void  concat3(char c1[], char c2[], char result[]) {
    
    int i;

    for (i = 0; c1[i] != 0; i++) {
        result[i] = c1[i]; 
    }

    for (int j = 0; c2[j] != 0; j++) {
        result[i + j] = c2[j];
    }

}