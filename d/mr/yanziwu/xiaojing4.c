// /d/mr/xiaojing1-4.c

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",GRN"С��"NOR);
	set("long",@long
һ�����������ɶ���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ��
׺�����С�������ʯ���ϣ�ž�žવķ�������������˳��С�����淽��
��ȥ��һ���ճ���
long);
	set("outdoors","Ľ��");
	set("exits",([
		"north":__DIR__"guanxing",
		"east" : __DIR__"fenmu",
		"west" : __DIR__"xiaojing3",
	]));
	set("objects",([
		__DIR__"../npc/deng" : 1,
	]));
	setup();
}
