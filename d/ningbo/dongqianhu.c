// Room: /u/beyond/ningbo/dongqianhu.c ��ǰ��
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��Ǯ��");
	set("long", @LONG
������һ����ʯ·�ϣ�������һƬï�ܵ������֣�ͷ��Сϲȵ����������
�и���ͣ��һ��΢�紵����ʹ��о���һ�ɳ�ʪ�Ŀ��������������ʱ������
���˶�Ǯ���ϣ�ֻ��ˮ�����������ɽɫ���죬����ɽɫ�������ˡ�����С��
���ۺ��ϣ�ʹ����ø���ʫ�黭�⡣
LONG
	);
	set("outdoors", "����");
	set("exits",([
		"west" : __DIR__"ningbo",
		"north" : __DIR__"xikou",
		"southwest" : __DIR__"kedian",
		"south" : __DIR__"xuedoushan",
	]));
	setup();
}
