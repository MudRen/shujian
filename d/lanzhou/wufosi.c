//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������������Χȫ��ɳ������������Ѿ�������������
�������ɳ����ң��Ӱ���Ľ���������ϡ���Ա���������¡������֣�Ψ
һ���������Ľ����Ǵ����ݶ���ȫ�ǿ�����ǿ���������紵������������
����---��---������
LONG );
	set("exits", ([
		"south"     : __DIR__"shimen",
	]));

	set("objects",([
		__DIR__"npc/sengren" : 1,
	]));

	setup();
}
