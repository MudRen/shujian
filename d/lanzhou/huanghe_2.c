// by xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ�");
	set("long", @LONG
�ƺӳ����ຣ��������֮�����ܵ�������ԭ���赲��ת���򶫱���ȥ��
������������ԭ�Ĺ�������ɳ����������ˮɫ�λƣ��ͱ���Ϊ�ƺӡ�
LONG );
	set("exits", ([
		"east"      : __DIR__"huanghe_3",
		"northwest" : __DIR__"jintai",
	]));

	set("outdoors", "����");
	setup();
}
