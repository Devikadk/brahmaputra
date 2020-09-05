#include <stdio.h>
#include <string.h>
/* xml handling library */
#include <libxml/parser.h>
#include <libxml/tree.h>
int main()
{
    xmlDoc         *document;
    xmlNode        *root, *first_child, *node,*temp;
    char           *filename;
    
   
    filename = "ss.xml";
    /*Open file in read mode */
    document = xmlReadFile(filename, NULL, 0);
    /*Get the root element node */
    temp = xmlDocGetRootElement(document);
    root=xmlFirstElementChild(temp);
  
        char* id[8];
        char* Value[8];
        int i=0;
        first_child = root->children;
        for (node = first_child; node; node = node->next) {

            if(node->type==1)
            {
                id[i]=(char*)node->name;
                Value[i]=(char*)xmlNodeGetContent(node);
                i++;
            }
        }

    root=xmlLastElementChild(temp);
    first_child = root;
        for (node = first_child; node; node = node->next) {

            if(node->type==1)
            {
                id[i]=(char*)node->name;
                Value[i]=(char*)xmlNodeGetContent(node);
                i++;
            }
        }
        
        //root=xmlLastElementChild(temp);
    int size = sizeof id / sizeof id[0];
    for(i=0;i<=size;i++)
    {
        printf("%s :%s\n",id[i],Value[i]);
    }
    

  // fprintf(stdout, "...\n");
    return 0;
    
    }
