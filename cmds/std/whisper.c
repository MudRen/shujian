// whisper.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("��Ҫ��˭����Щʲô��\n");

	ob = present(dest, environment(me));
	if (ob == me) return notify_fail("���Լ����\n");
	if( !ob || !ob->is_character() )
		return notify_fail("��Ҫ��˭���\n");

	write( GRN "����" + ob->name() + "�Ķ�������˵����" + msg + "\n" NOR);
	message("wizard", "(" + capitalize(me->query("id")) + ")", environment(me), me);
	tell_room( environment(me), me->name() + "��" + ob->name()
		+ "����С����˵��Щ����\n", ({ me, ob }) );
	if (!wizardp(me) && !wizardp(ob))
		message("wizard", GRN "(" + msg + ")\n" NOR, environment(me));
	if (!userp(ob)) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "����Ķ�������˵����" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
ָ���ʽ��whisper <ĳ��> <ѶϢ>

���ָ�����������ͬһ�����е��˶������ NPC ���ڡ�
TEXT
	);
	return 1;
}
