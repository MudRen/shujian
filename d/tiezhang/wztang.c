// Room: /tiezhang/wztang.c

#include <ansi.h>
inherit ROOM;

string look_bian();

void create()
{
	set("short", HIY"��ָ��"NOR);
	set("long", @LONG
����һ����ȫ�û��������ɵĴ�����͸��������˵ĺ�������������û��
�������Ե���ɭ�ڰ������Ե�ǽ���ϲ������ͻ�ѣ�ɢ������ƵĹ������ž�
�Ĵ����в�ʱ��������ž��ȼ���������������аڷ��Ű����ı��������Է�
����ʮ�������ӣ�ֻ���������д���ʱ�������Ż��������벿�����顣������
��ǽ�Ϲ���һ���ƽ�ĺ���(bian)��������һ��С��ͨ����档
LONG
	);
	set("item_desc", ([
		"bian" : (: look_bian :),
	]));

	set("exits", ([
		"east" : __DIR__"zoulang-1",
		"southdown" : __DIR__"guangchang.c",
		"west" : __DIR__"zoulang-2.c",
		"north" : __DIR__"hxfang.c",
	]));
	set("objects", ([
		__DIR__"npc/mayi1" :1,
		__DIR__"npc/huiyi" :2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") != "���ư�"
	 && present("hong xiaotian", environment(me))
	 && (dir =="west" || dir =="north" || dir=="east"))
		return notify_fail("��������ס���ȥ·����ȭ�����Ǳ�����Ӳ������ڡ�\n");

	return ::valid_leave(me, dir);
}

string look_bian()
{
	return
	"\n"
	     HIY"          ����������������������������������\n"
		"          ������  ������������������    ����\n"
		"          ����   ��    ָ    ��    ��   ����\n"
		"          ����  ��������������������    ����\n"
		"          ����������������������������������\n"NOR;
}
