// Room: /d/shaolin/twdian.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"������"NOR);
	set("long", @LONG
�����������µ��е�����������������ƣ�᣽Ƕ��ˡ�����ǰ��Ҫ
��ʢ�Ķࡣ��ǰ�����Ÿ�����ӣ��ƺ���Զ��Ц��������շ��Ĵ�������
�����ԣ���ִ�������˳�������������ϰ������ļ����ߣ����յ����վ��
����Τ�ԡ�ֻ���������ף�����Ӣ�����������ݣ�˫�ֺ�ʮ������ƺ��
���ϡ�
LONG
	);

	set("exits", ([
//		"east" : __DIR__"twdian1",
//		"west" : __DIR__"twdian2",
		"south" : __DIR__"qdian",
		"north" : __DIR__"sblu-1",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/dao-guo" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x",50);
  set("coor/y",240);
   set("coor/z",110);
   setup();
}



