// By River@SJ

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����һ����̫�ߵ�Сɽ��ɽ����ȥ�����������Ʈ�ż��䵭���İ��ơ�һ
Ⱥ���㷢�����¸¡��Ľ�������ͷ�Ϸɹ�������ɽ�³��ǵĲ�ԫ�ϱ���ϡ�ɱ档
·����һ������֮�Ͽ����״ʡ�
LONG );
	set("exits", ([
		"southeast" : "/d/changan/westroad2",
		"westdown" : __DIR__"jingyuan",
	]));

	set("outdoors", "����");
	setup();
}
