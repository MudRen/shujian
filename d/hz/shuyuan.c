// /u/beyond/hz/shuyuan.c  ��Ժ
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"��Ժ"NOR);
	set("long", @LONG
��������Ժ�Ľ��ã�����������һ����Ⱦ��һλׯ���������������̫
ʦ���Ͻ�ѧ���Ǿ��ǵ�������������ˡ�������������������ѧ��ѧ����һ
�Ź��ⰻȻ���鰸������������ǰ�棬���ϰ��ż��������˵���װ�鼮����
�����������һ�����(shujia)�����ڶ��������ʯ�̣������Ժ��ʷ����
�á�ֵ��һ�����Ƕ�ڽ���ǰ��ڵ�ѧ��(xuegui)��
LONG
	);

	set("exits", ([
		"west" : __DIR__"qsddao6",
	]));

	set("item_desc", ([
		"xuegui" : "�ս����������տ���Ŀ��ҳ��"  
			"\nͨ��ʱ�������ζ�����ʫ����" 
			"\n���������ʣ���ΰ�ʱ���ꡣ"
			"\nҹ���Խ���������Ҫ������\n\n"
	]));
	
	set("objects", ([
		__DIR__"npc/xiansheng": 1,
	]));

	set("coor/x",110);
  set("coor/y",-320);
   set("coor/z",0);
   setup();
}
/*
int valid_leave(object me, string dir)
{
	me->delete_temp("mark/��", 0);
	return 1;
}
*/

