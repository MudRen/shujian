// �÷���
// caifengpu1.c
// augx@sj 10/9/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIC"�÷���"NOR);
	set("long",
"���Ǽ�װ諺����Ĳ÷��̣������ﵽ�������˸ո����õ��·���ñ�ӡ�Ь
�ӵȵ��������Ҳ÷��̵����ﳤ���ǣ���ٹ������ﲻ����ʮ������������
�ǻ������źܴ�Ĳ÷�������������Ĳ÷��������ӱ�æµ�š�
");

	set("objects",([
		__DIR__"npc/caifeng" : 1,
		__DIR__"obj/caifengzhuo" : 1,
	]));

	
	set("exits",([
		"east" : "/d/changan/northjie2",
	]));
	
	set("indoors", "������");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
