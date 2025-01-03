typedef struct valuestruct // structure pour les valeurs collectés de split -> color = valeur hexidecimal apres la virgule SI IL Y EN A  
{
    int color;
    int z_value;
}v_struct;

v_struct    parsenbr(char *charnbr)
{
    int i;
    v_struct colornbr;
    char *temp;

    temp = malloc(sizeof(charnbr));
    if (!temp)
        return (NULL);
    i = 0;
    while (charnbr[i] != '\0')
    {
        temp[i] = charnbr[i];
        if (temp[i] == ',')
            colornbr.z_value = ft_atoi(temp);
        i++;
    }

}
