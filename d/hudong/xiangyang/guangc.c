// leitai.c ��̨ǰ�㳡

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��̨ǰ�㳡");
	set("long",@long
������������̨ǰ���һ�����͹㳡���������������̨�ϱ��䣬����
����ɽ�˺��������Ҳ���������֣���ô��������̨���Ա��԰ɡ�
long);
        set("xyjob", 1);
	set("exits",([
		"tiandi" : "/d/wizard/lt",
		"fengyun" : "/d/wizard/lt1",
		"longhu" : "/d/wizard/lt2",
		"north" : __DIR__"bcx2",
	]));
	set("outdoors", "����");
	set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	object *ob;
	int i;

	if (dir != "north" && (!userp(me) || sizeof(me->query_entire_conditions())))
		return notify_fail(HIW"\n�㻹��Ҫ���������ý�����̨�صأ�\n"NOR);
	if ( dir != "north" && me->query("no_quest"))
		return notify_fail("\n");
	ob = deep_inventory(me);
	i = sizeof(ob);
	while (i--)
	if ((ob[i]->is_character() || ob[i]->query("unique")) && dir != "north")
		return notify_fail(HIW"\n�㲻�ô��˻�����������̨�صء�\n"NOR);
	return ::valid_leave(me, dir);
}
