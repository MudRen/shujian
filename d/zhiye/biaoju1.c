// Room: /d/zhiye/biaoju1.c
// Date: Look 99/09/20
// augx@sj  9/18/2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY "�����ھ�" NOR);
	set("long", @LONG
����һ���������˽���ϴ��֮�󿪵�һ���ھ֣������ʦ�����������
�������£���һ���ǰ�ʱ��ɡ����������񣬺ܶ཭�����˶�Ը����������
�¡�
LONG
	);
	
	set("indoors", "����");

	set("exits", ([
		"south" : "/d/city/dongmen",
	]));
	
	set("objects", ([
		__DIR__"npc/biaotou" : 1,
	]));
	
	set("indoors", "����");
	set("incity",1);
	setup();
}

