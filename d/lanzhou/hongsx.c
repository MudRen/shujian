//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ɽϿ");
	set("long", @LONG
��ɽϿ�Ǹ��ǳ��վ���Ͽ�ȣ���������ʮ�ɵĻ����£����Ƕ��ͣ��м�ֻ
��һ������ͨ��һ��һ���խ�����׳ơ�һ���족������û��ʲô���ȴ��
���ó�������ʧ�١�
LONG );
	set("exits", ([
		"north"     : __DIR__"shimen",
		"southeast"     : __DIR__"jintai",
	]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));

	set("outdoors", "����");
	setup();
}
