// multi-update

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i, n;
        object obj, *inv;
        string err;
        mixed *file;
  
        seteuid( geteuid(me) );

        if( !arg )
                return notify_fail("ָ���ʽ��mupdate <·��>\n");

        if( arg[strlen(arg)-1]!='/' ) arg += "/";
        if(  file_size(arg)!=-2 )
                return notify_fail("û�����Ŀ¼��\n");

        file = get_dir(arg);
        if( !sizeof(file) )
                return notify_fail(arg + " is empty \n");

        for( i = 0; i < sizeof(file); i++ ) {
                if( !sscanf(file[i], "%*s.c") ) 
                        continue;
                
                file[i] = arg + file[i];
                if( file_size(file[i]) < 0 ) {
                        write("û��" + file[i] + "���������\n");
                        continue;
                }

                me->set("cwf", file[i]);

                if (obj = find_object(file[i])) {
                        if( obj==environment(me) ) {
                                if( file_name(obj)==VOID_OB ) {
                                        write("�㲻���� VOID_OB �����±��� VOID_OB��\n");
                                        continue;
                                }
                                inv = all_inventory(obj);
                                n = sizeof(inv);
                                while(n--)
                                        if( userp(inv[n]) ) inv[n]->move(VOID_OB, 1);
                                        else inv[n] = 0;
                        }
                        destruct(obj);
                 }
                 if (obj) {
                        write("�޷�����ɳ�ʽ�롣\n");  
                        continue;
                        }

				err = "/binaries"+file[i][0..<3]+".b";
				write("ɾ���������ļ� "+err+" ...");
				if( file_size(err) < 0 ) write("�����ڡ�\n");
				else if (rm(err)) {
					write("�ɹ���\n");
				} else write("ʧ�ܡ�\n");

				write("���±��� " + file[i] + " ...");
				err = catch( call_other(file[i], "???") );
                 if (err)
                        printf( "��������\n%s\n", err );
                 else {
                        write("�ɹ���\n");
                        if( (n = sizeof(inv)) && (obj = find_object(file[i]))) {
                               while(n--)
                                      if( inv[n] && userp(inv[n]) ) inv[n]->move(obj, 1);
                               }
                      }
             }

        return 1;
}
