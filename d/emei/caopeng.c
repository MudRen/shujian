// caopeng.c
// ����
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
���Ƕ���ɽ����һ���򵥵Ĳ�����϶���Щ�ϻ����ܶ���ɽ���οͶ���
������Щ��ɽ��Ʒ��
long);
	set("exits",([
       "east" : __DIR__"qingshijie",
]));
set("objects",([
__DIR__"npc/xiaofan" : 1,
]));
	set("coor/x",-170);
  set("coor/y",-110);
   set("coor/z",0);
   setup();
}
	    	
