// foubing1.c ��ɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"��ɽ"NOR);
	set("long", @LONG
����һ��ܴ󸡶���ɽ����������������ɡ�����ǰ��ı�ɽ�ܵ���ɽ֮
�ȣ����ϵ��ۻ�������������������ม�����ϵ����������Ա�ɽ�ǲ��ϵĿ�
����ɽ��
LONG);
	set("no_fight", 1);
	set("no_get_from", 1); 
	set("no_sleep_room", 1);
	set("outdoors","����");
	setup();
}

void run(object ob)
{
	if (!ob || environment(ob)!= this_object()) return;
	tell_object(ob, HIW"\n��ɽ��������Ʈȥ��\n\n"NOR);
	ob->move(__DIR__"foubing2");
}

void init()
{
	call_out("run", 20+random(10), this_player());
}
