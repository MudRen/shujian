// jyt.c ������
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
	set("short",HIW"������"NOR);
	set("long", @LONG
�����ǽ����ټ�����ʹ�ߣ��Ĵ󻤷�����ɢ�ˣ����������������̵�����
�鷴Ԫ����������ȥ�񣬳��������ĶԲߵĵط��������������������ʨ��
��������ʥ���á�
LONG);    
	set("exits", ([
		"south" : __DIR__"xting",
		"northup" : __DIR__"sht",
		"east" : __DIR__"shiwang",
		"west" : __DIR__"longwang",
	]));             
	set("objects",([
		__DIR__"npc/f-dizi" : 2,
		CLASS_D("mingjiao") + "/fan" : 1,
	]));
	setup();    
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	int i;
	object ob;
	myfam = (mapping)me->query("family");
	i = me->query_skill("shenghuo-shengong", 1);
	i += me->query_skill("jiuyang-shengong", 1);

	if((!myfam || myfam["family_name"] != "����")
	 && dir == "northup" 
	 && objectp(ob=present("fan yao", environment(me))) 
	 && living(ob))
		return notify_fail("��ң����һ����ס���ȥ·��\n"NOR);  
	if( i < 70 
	 && dir == "northup"
	 && objectp(ob=present("fan yao", environment(me))) 
	 && living(ob))
		return notify_fail("��ң������ҡ��ҡͷ���������ں�æ�����Ժ������ɡ�\n"NOR);          
	return ::valid_leave(me, dir);
}
