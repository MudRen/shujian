// /d/city/damingsi.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"������"NOR);
	set("long",@long
���������ƴ���ɮ���潲ѧ�;�ס�ĵط�����ǰ��������¥����¥������
�Ǵ��۱��������ǰΪ�����������ʮ���޺��񡣴��Ķ����Ƕ�Է����
����ո�
long);
	set("exits",([
		"north" : __DIR__"xidajie2",
	]));
	set("coor/x",90);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",-10);
   set("coor/z",0);
   set("incity",1);
	setup();
}
