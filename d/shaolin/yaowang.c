//yaowang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"ҩ��Ժ"NOR);
	set("long", @LONG
һ��ҩ��Ժ���˱Ƕ�������Ũ����ҩ�㡣������������װ������ҩ�ĵ�
��ҩ��ÿ��ҩ�����ϰٸ�װҩ�ĳ��������˸���ҩ����������һ���޴�
��ɼľ�񣬹������ŷ���ӡ�ķ�����һλ����ɮ��������æµ��ָ����ִ��
ɮ����ҩƷ����ҩ������
LONG
	);

	set("exits", ([
		"west" : __DIR__ "songshu1",
       ]));
         set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
	]));

	
	set("coor/x",80);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}



