//value.c

#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
    	float value;
        object ob;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("��Ҫ��ʲô�ۣ�\n");

	if(!clonep(ob)
	||ob->query("unique")
	||ob->query("no_get")
	||ob->query("no_give")
	||ob->query("no_drop")
	||ob->query("quest")///////////
	||ob->is_corpse()
	||ob->query("food_remaining")
	||ob->query("liquid")
	||ob->query("material")=="meat"//�⣿
	||ob->query("money_id")
	||strsrch(file_name(ob),"/d/city/weapon/")==0
	||ob->is_character()
	//||obj->query("")
	//||obj->query("")
	//||obj->query("")
	//||obj->query("")
	) return notify_fail(ob->name()+"�����Ա����棬Ҳ���ù��ۡ�\n");
	
	value = ob->query("value");
	if (value < 30)
		return notify_fail(ob->name()+"һ�Ĳ�ֵ��\n");
	else
	
	if (me->query("registered") == 3)
	tell_object(me,ob->name()+"ֵ"+ MONEY_D->price_str(value) + "�����˴�������Ա��棬���ǹ���û�����ŷ�����Ҫ"
		+MONEY_D->money_str("/inherit/room/miscroom.c"->get_value2(86400,to_float(value/2)))+"/�졣\n" );
	else
	tell_object(me,ob->name()+"ֵ"+ MONEY_D->price_str(value) + "�����˴�������Ա��棬��ŷ�����Ҫ"
		+MONEY_D->money_str("/inherit/room/miscroom.c"->get_value2(86400,to_float(value)))+"/�졣\n" );

	return 1;
}


int help(object me)
{
    write(@HELP
ָ���ʽ : value <��Ʒ����>
 
���ָ������������Ʒ���й��ۣ�������ʾ���˴�����ı��ܷ��á�
 
HELP
    );
    return 1;
}
 
