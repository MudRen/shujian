// /d/city/dhq.c
// this is made by beyond
// update 1997.7.5
#include <ansi.h>

inherit ROOM;

void create ()
{
	set("short",HIR"�����"NOR);
	set("long",@long
����ź����������֮�ϣ�����԰��ˮͨ�򳤵̴����Ĵ��š������ϵĺ�
ɫ���˶��ƺ��š�ʫ���������С����ŷɿ�ˮ���У�һ�����˾����죬���续
�����¹���������Ӱ̫�Ҵҡ��䣬��һ���ʺ�Ӻ��Ķ����ɿ�������
long);
	set("exits",([
		"south" : __DIR__"sxh",
		"east" : __DIR__"xjs",
		"north" : __DIR__"hubian1",
	]));
	set("outdoors", "����");
	set("coor/x",90);
  set("coor/y",30);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",30);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",30);
   set("coor/z",0);
   set("coor/x",90);
  set("coor/y",30);
   set("coor/z",0);
   set("incity",1);
	setup();
}
