#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string str)
{
        object *ob;
        int i;
        object obj;
        if(!me->query_temp("confim_daunwu"))
        {
        	me->set_temp("confim_daunwu",1);
        	return notify_fail("���Ƕ����ר�õ�Ŷ��������һ�� ȷ����û�Ǵ� ������ʵ�ǹ����ա�\n");
        }
        me->delete_temp("confim_daunwu");
	ob = filter_array(children(USER_OB),(:clonep:));
	i = sizeof(ob);		
	while (i--) {
		if(!objectp(obj = new(FOOD_D("super_zongzi")))) continue;
		if(!ob[i]||!objectp(ob[i])) continue;
		obj->move(ob[i]);
		tell_object(ob[i],BLINK HIC"������֣�Ԥףÿ�춼��ô���֣�\n"NOR);
		message_vision("ͻȻ������һ��"HIW+obj->name()+NOR"����$N�Ļ��\n",ob[i]);
		message_vision("$N���˵ó�������ȥ������£������������ۣ����ŵ��������㣬��һ����ҧ��һ�ڣ����ķ��Ͼ������⣬���������ҵ������� \n",ob[i]);
		tell_object(ob[i],HIM"��Ȼ������ܺã�����ԭ˵����������壬�ٴ��齫�����ܶ�����ӣ����콡����\n"NOR);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
	����������ڿ��֣�
HELP
	);
	return 1;
}