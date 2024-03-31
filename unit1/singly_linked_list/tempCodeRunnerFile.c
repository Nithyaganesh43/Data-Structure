printf("\n1.starting\n2.end\n3.position\nwhere to insert(1/2/3):");
      int option,s;
      scanf("%d",&option);
    switch(option){
        case 1:
        s=append_start(&head,data);
        case 2:
        s=append_end(&head,data);
        case 3:
        s=append_position(&head,data);
      
    } 