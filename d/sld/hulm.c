// hulm.c
// ����������
inherit ROOM;
void create()
{
	set("short","������������");
	set("long",@long
�˴��ǻ����ŵ��������������Ŵ��Ŵ���һ�Ŵ�������ǽ���ã�����
�����ε���Χ������ֻ���ʿ�ǽ���š�
long);
	set("exits",([
	    "east" : __DIR__"hulmws",
          "west" : __DIR__"hulmlgf",
          "out" : __DIR__"sanpo4",
]));
set("objects",([
"/kungfu/class/sld/yq" : 1,
__DIR__"npc/yejz" : 3,
]));
	set("coor/x",500);
  set("coor/y",440);
   set("coor/z",70);
   setup();
}
	    	
