int _strlen_recursion(char *s)
{
    static int length = 0;
    
    if(*s != '\0' )
    {
        length++;
        _strlen_recursion(++s);
    }
    else
    {
      return length;  
    }
}
