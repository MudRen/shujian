//Created by emnil 2000 03 03

inherit F_CLEAN_UP;

mixed main(object me, string arg, int remote)
{
   string str,where,dir,fn,ff;
   string * line;
   mixed* files;
   int j,pp,f,i;
   string * wr=({"","","","","","","","","",""});
   int * pos=({0,0,0,0,0,0,0,0,0,0});

  
   
   
   

   if( !arg || sscanf(arg, "%s from %s", str, where)!=2 )
     return notify_fail ("ָ���ʽ: findtstr <string> from <path>(��:/d) \n");
   
   pp=0;
   f=0;
   while(1)
   {
        if(where!="/")
   	dir=where+"/";
        else
        dir=where;
	files=get_dir(dir,-1);
	for(j=f;j<sizeof(files);j++)
	{
		fn=dir+(string)files[j][0];
		if((int)files[j][1]==-2)
		{		 
			wr[pp]=where;
			pos[pp]=j+1;
			where=fn;
			f=0;
			pp=pp+1;
			break;
		}
		else
		{
			ff=read_file(fn);
			line = explode(ff, "\n");
			for(i=0;i<sizeof(line);i++)
			{
                if(strsrch(line[i],str,0)!=-1)
				{
					write(sprintf("����%s��%s�ĵ�%d�С�\n",str,fn,i+1));
				}
			}
		}
	}
	if(j>=sizeof(files))
   	{
		if(pp>0)
		{
			pp=pp-1;
			where=wr[pp];
			f=pos[pp];
		}
		else
			break;
   	}
   }	
        write("������ϡ�\n");
   return 1;
}

int help (object me)
{
        write(@HELP
        ָ���ʽ : findstr str from path(��:/d/city)
 
���г�������str�������ļ������ּ�str���ڵ�������
 
HELP
);
        return 1;
} 

