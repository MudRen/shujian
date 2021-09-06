// finger.c
// by xiaoyao@Sj
// �����������
// Modify by snowman@SJ 09/01/2000
// Added busy time, by snowman@SJ 26/08/2000

#include <ansi.h>
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

void remove_busy(object me)
{
	if ( me) me->delete_temp("command_busy");
}

int main(object me, string arg)
{
	int i;
	object obj;
	string *friend_user, list;

	friend_user = me->query("friend_user");

	if( !stringp(arg)) {
		if (!sizeof(friend_user))
			return notify_fail("��Ŀǰû���趨���ѡ�\n");

		friend_user = sort_array(friend_user, 0);
		list = "\n��Ŀǰ�ĺ����������£�\n";
		for( i = 0 ; i < sizeof(friend_user); i++) {
			if( (obj = LOGIN_D->find_body(friend_user[i]) )){
				if( me->visible(obj) ) list += sprintf("  [%2d] %s\n", i+1, obj->short(1));
				else list += sprintf("  [%2d] %-9sĿǰ�������ϡ�\n", i+1, capitalize(friend_user[i]));
			} else	// if( file_size(DATA_DIR+"login/"+ friend_user[i][0..0] +"/"+ friend_user[i] +__SAVE_EXTENSION__) > 0 )
				list += sprintf("  [%2d] %-9sĿǰ�������ϡ�\n", i+1, capitalize(friend_user[i]));
/*
			else {
				list += sprintf("  [%2d] %-9s"HIR"�Ѿ�", (i+1), capitalize(friend_user[i]));
				if (file_size(DATA_DIR+"login/"+ friend_user[i][0..0] +"/"+ friend_user[i] + ".ppp") > 0)
					list += "��ɾ��";
				else list += "��ɱ";
				list += "�ˡ�\n"NOR;
			}
*/
		}
		write(list);
		return 1;
	} else {
		if( arg == "-all" ){
			if( !wizardp(me) )
				return notify_fail("-all Ϊ��ʦר�á�\n");
			else me->start_more( FINGER_D->finger_all() );
			return 1;
		}

		if( sizeof(friend_user) && sscanf(arg,"-d %s", arg) ) {
			if( friend_user -= ({ arg }) )
				if( me->set("friend_user", friend_user) )
					return notify_fail("�㽫 "+capitalize(arg)+" �Ӻ��������Ƴ��ˡ�\n");
			else return notify_fail("��ĺ��������в�û�� "+capitalize(arg)+" ����ˡ�\n");
		}

		else if( sscanf(arg, "-a %s", arg) ) {
			if( arg==me->query("id") )
				return notify_fail("���Դ���������xixi\n");

			if (!sizeof(friend_user)) {
				if (me->set("friend_user", ({arg})))
					return notify_fail("��ɹ��Ľ� "+capitalize(arg)+" ��������������档\n");
			}

			if (member_array(arg, friend_user) != -1)
				return notify_fail("�����������Ѿ��д����ˡ�\n");

			if (sizeof(friend_user) > 9)
				return notify_fail("�����������Ϊʮλ������ȷ��������\n");

			if( file_size(DATA_DIR+"login/"+arg[0..0]+"/"+ arg +__SAVE_EXTENSION__) < 0 )
				return notify_fail("û����λʹ���ߡ�\n");

			friend_user = sort_array(friend_user + ({ arg }), 0);

			if (me->set("friend_user", friend_user))
				return notify_fail("��ɹ��Ľ� "+capitalize(arg)+" ��������������档\n");

			return notify_fail("�� "+capitalize(arg)+" �����������ʧ�ܣ���֪ͨ��ʦ��\n");
		} else {
			if( !wizardp(me) ) {
				if( me->query_temp("command_busy")) return notify_fail("����æ���ء�\n");
				if( (int)me->query("jing") < 50 ) return notify_fail("��ľ����޷����С�\n");
				me->receive_damage("jing", 50);
				me->set_temp("command_busy", 1);
				call_out("remove_busy", 3, me);
			}
			write( FINGER_D->finger_user(arg) );
		}
	}

	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��finger [-a|-d|-all]
	  finger <id>
	  finger
--------------------------------------------------
 finger [ʹ��������]   : ��ȡ���˵�����
 finger -a [�������]  : �����˼����������
 finger -d [�Ƴ�����]  : �����˴Ӻ���������ɾ��
 finger		: ��ʾ��������
 finger -all	   : ȫ�������ϸ����(��ʦר��)
--------------------------------------------------

HELP
    );
    return 1;
}
