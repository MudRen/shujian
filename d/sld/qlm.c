// qlm.c
// ����������
inherit ROOM;
void create()
{
	set("short","������������");
	set("long",@long
�˴��������ŵ��������������Ŵ��Ŵ���һ�Ŵ�������ǽ���ã�����
�����ε���Χ������ֻ���ʿ�ǽ���š�
long);
	set("exits",([
	    "east" : __DIR__"qlmws",
          "west" : __DIR__"qlmlgf",
          "out" : __DIR__"sanpo5",
]));
set("objects",([
"/kungfu/class/sld/xxt" : 1,
__DIR__"npc/greenjz" : 3,
]));
	set("coor/x",510);
  set("coor/y",430);
   set("coor/z",50);
   setup();
}
	    	
