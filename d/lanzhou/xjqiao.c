// By River@SJ

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����ݺ͹����м䣬������ˮ������������ˮ�ļ����Ӵ���������ĳߣ�
խ�������࣬�ȴ��ѹ����ഫ����䣬����һλ���մ������������֮������
���ɽ����Ѿ���˽���������ţ��������ݣ����ȶȱ��š�
LONG );
	set("exits", ([
		"northwest"    : __DIR__"gulang",
		"southeast" :  __DIR__"yongdeng",
	]));
	set("outdoors", "����");
	setup();
}
