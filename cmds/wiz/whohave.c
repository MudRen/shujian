// whohave.c
//wzfeng 98 10 30
// Modified by Numa 2000.2.19
// Modify By River@SJ 2000.2.19 ���������wiz clone���б�� :)

#include <ansi.h>
inherit F_CLEAN_UP;

void listing (object who, string prefix, string arg)
{
        object *ilist;
        int j;
        string clone, clone_by;

	if (arg == "wiz_ob")
	{
        	ilist = all_inventory(who);
        	if (! ilist)
                	return;
        	j = sizeof(ilist);
        	while (j--) {
                	object ob = ilist[j];
               		if (ilist[j]->query("clone_by_wizard")) {
	        		write (sprintf("%2s%8s%-10s : ",prefix,who->query("name"),"("+who->query("id")+")"));
       	        		clone = HIR BLINK+"*"+NOR;
               			clone_by = !ilist[j]->query("clone_by_which_wizard")?"":"��("+ilist[j]->query("clone_by_which_wizard")+")";
               			write (" "+clone+ob->short()+" --> " + base_name(ob)+".c  " + clone_by + "\n");
               			continue;
               		}
        	}
        	j = sizeof(ilist);
        	while (j--) {
                	object ob = ilist[j];
                	listing (ob, "  "+prefix, arg);
        	}
	}
	else {
        	if (! present (arg,who))
                	return;
        	write (sprintf("%2s%8s%-10s : ",prefix,who->query("name"),"("+who->query("id")+")"));
        	ilist = all_inventory(who);
        	if (! ilist)
                	return;
        	j = sizeof(ilist);
        	while (j--) {
                	object ob = ilist[j];
                	string *ids = ob->parse_command_id_list();
               		if (ilist[j]->query("clone_by_wizard")) {
	       	        	clone = HIR BLINK+"*"+NOR;
        	       		clone_by = !ilist[j]->query("clone_by_which_wizard")?"":"��("+ilist[j]->query("clone_by_which_wizard")+")";
               		}
               		else {
               			clone ="";
               			clone_by ="";
               		}
               		if (member_array(arg, ids) == -1)
                       		continue;
               		write (" "+clone+ob->short()+" --> " + base_name(ob)+".c  " + clone_by);
        	}
        	write ("\n");
        	j = sizeof(ilist);
        	while (j--) {
	                object ob = ilist[j];
        	        listing (ob, "  "+prefix, arg);
        	}
        }
}	

mixed main(object me, string arg, int remote)
{
        object *ulist;
        int i;

        if (!arg)
                return notify_fail ("ָ���ʽ��whohave <id|-wiz>\n");
	if (arg == "-wiz")
       		arg = "wiz_ob";
        ulist = users();
        i = sizeof(ulist);
        while (i--) {
                listing (ulist[i], "  ", arg);
        }
        return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ : whohave <id|-wiz>
 
���г�ĿǰЯ��ĳ����Ʒ����ҡ����������"-wiz"��
����ʾ����������ʦ������Ʒ�б�
 
 
HELP
);
        return 1;
}
