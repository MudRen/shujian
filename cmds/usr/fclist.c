// revenge.c 

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	int i;
	object obj;
        mapping revenge_list;  
	string revenge_user, list;

	revenge_list = me->query("revenge");

        if (!sizeof(revenge_list))
	  return notify_fail("��Ŀǰ���������ǿյġ�\n");

		list = "\n��Ŀǰ�ĸ����������£�\n";

		for( i = 0 ; i < sizeof(revenge_list); i++) {
                     revenge_user= keys(revenge_list)[i];

			if( (obj = LOGIN_D->find_body(revenge_user) )) {
				if( me->visible(obj) ) list += sprintf("  [%2d] %s\n", i+1, obj->short(1));
				else list += sprintf("  [%2d] %-9sĿǰ�������ϡ�\n", i+1, capitalize(revenge_user));
			                                                 } 
                            else  if( file_size(DATA_DIR+"login/"+ revenge_user[0..0] +"/"+ revenge_user +__SAVE_EXTENSION__) > 0 )
				list += sprintf("  [%2d] %-9sĿǰ�������ϡ�\n", i+1, capitalize(revenge_user));

			     else if (file_size(DATA_DIR+"login/"+ revenge_user[0..0] +"/"+ revenge_user + ".ppp") > 0)
				list += sprintf("  [%2d] %-9s"HIR"�Ѿ���ɱ��", i+1, capitalize(revenge_user));
			    
                             else	
				list += sprintf("  [%2d] %-9s"HIR"�Ѿ���ɾ����",i+1, capitalize(revenge_user));

			}
	
		write(list);

		return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��fclist
            ��ѯ�Լ��ĳ������
HELP
    );
    return 1;
}
