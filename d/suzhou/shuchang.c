#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�鳡");
	set("long",@long
�����Ǹ����ֵ��鳡������������������������ˡ�����ǰ������Ӻ���
��һλ˵��������������ȥ����ʮ�꣬��������һ����壬���ھ۾������˵
������--����ҽ��������е����ǲ�ʱ�ķ�����̾�ͺȲ�����ʱ��ʱ��ͭ����
����ȥ��
long);
	set("item_desc", ([
		"door" : "����һ��ͨ�����õ�Сľ�š�\n"
	]));
	set("objects",([
		__DIR__"npc/gongzige" : 1,
	]));
	set("exits",([
		"enter" : __DIR__"houtang",
		"south" : __DIR__"xidajie2",
	]));

	create_door("enter", "С��", "out", DOOR_CLOSED);
	set("incity",1);
	setup();
}
