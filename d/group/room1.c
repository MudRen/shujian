// room1 ��׼����
// by augx@sj  3/19/2002

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ھ�");
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
	//	__DIR__"npc/biaotou" : 1,
	]));


	set("ingroup",1);
	setup();
}

