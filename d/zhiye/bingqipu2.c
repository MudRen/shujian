// ������
// bingqipu1.c
// augx@sj 9/5/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIY"������"NOR);
	set("long",
"����һ�Ҹ����ûʵı����̣�ǽ�Ϲ����������󵶡�������������ذ�׵�
�ȱ������ݽǻ�����һ����¯��¯��������յ�һƬͨ�졣��̨����վ��һλ
��̬���������ʦ�����������պã�����Ҳ�������Դ�Ҷ�Ը������������
������
");

	set("objects",([
		__DIR__"npc/zhujian-shi" : 1,
		__DIR__"npc/hantiejiang" : 1,
		__DIR__"obj/zhujianlu" : 1,
	]));

	set("exits",([
		"north" : "/d/city/dongdajie0",
	]));

	set("indoors", "���ݳ�");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
