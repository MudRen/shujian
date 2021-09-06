

///���ָ���Ӧ�ó��õ�

inherit F_DBASE;
inherit F_SAVE;
inherit F_CLEAN_UP;

string filename;

string query_save_file()
{
        return filename;
}

int main(object me, string arg)
{
        mapping *notes;
        string *file;
        int num, i, j, k, l, m;
                
        file = get_dir("/data/board/");
        
        i = sizeof(file);
        if (!i) return 0;
        
        for(i=0;i<sizeof(file);i++)
        {
        	if(strsrch(file[i],"group")==0)
        	{
        		file -= ({file[i]});
        		i--;
        	}
        }
        ////////added By Ciwei
                	        
        i = sizeof(file);
        if (!i) return 0;
                                
	if (arg) {
		sscanf(arg, "%d", num);
		num--;
		if (num < 0 || num >= i)
			return notify_fail("û��������԰塣\n");
		return me->force_me("gg "
			+ ("/clone/board/"
			+ file[num][0..<3])->query("location"));
	}
        for (j = 0;j < i;j++) {
        	filename = "/data/board/"+file[j];        	
                //filename = resolve_path("/data/board/", file[j]);
                if (!restore()) return notify_fail("û������ļ���\n");
                notes = query("notes");
		k = me->query("board_last_read/" + query("board_id"));
		for (l = 0, m = sizeof(notes) - 1; m>=0; m--, l++)
			if (notes[m]["time"] <= k) break;
                write(j+1 + ". " + query("name"));
		if (sizeof(notes))
			write("����" + chinese_number(sizeof(notes)) + "������");
		else write("û������");
		if (l) write("��" + chinese_number(l) + "��δ��");
		write("��\n");
        }
	write("�� board xx ȥ�����뿴�����԰塣\n");
        return 1;
}
