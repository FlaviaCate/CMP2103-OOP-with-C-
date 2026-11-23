import std;
using namespace std;

char *cat2(const char *name, const char *addr)
{
    int nsz = strlen(name); //get the length of the name string
    int sz = nsz + strlen(addr) + 2; //calculate the total size needed
    char *res = (char *)malloc(sz); //allocate memory for the result string
    strcpy(res, name);

    res[nsz + 1] = '@'; // insert '@' character after the name
    strcpy(res + 2, addr); // copy the address string after the '@' character
    return res;
}

int main()
{
    char *email = cat2("Milton Obote", "uganda.com");
    cout << email << "\n";
    free(email); // free the allocated memory to avoid memory leaks
}
