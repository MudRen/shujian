// hlm.c
// ����������
inherit ROOM;
void create()
{
	set("short","������������");
	set("long",@long
�˴��Ǻ����ŵ��������������Ŵ��Ŵ���һ�Ŵ�������ǽ���ã�����
�����ε���Χ������ֻ���ʿ�ǽ���š�
long);
	set("exits",([
	    "east" : __DIR__"hlmws",
          "west" : __DIR__"hlmlgf",
          "out" : __DIR__"sanpo2",
]));
set("objects",([
"/kungfu/class/sld/zdy" : 1,
__DIR__"npc/blackjz" : 3,
]));
	set("coor/x",510);
  set("coor/y",430);
   set("coor/z",60);
   setup();
}
	    	
