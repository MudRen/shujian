// blm.c
// ����������
inherit ROOM;
void create()
{
	set("short","������������");
	set("long",@long
�˴��ǰ����ŵ��������������Ŵ��Ŵ���һ�Ŵ�������ǽ���ã�����
�����ε���Χ������ֻ���ʿ�ǽ���š�
long);
	set("exits",([
	    "east" : __DIR__"blmws",
          "west" : __DIR__"blmlgf",
          "out" : __DIR__"sanpo6",
]));
set("objects",([
"/kungfu/class/sld/zzl" : 1,
__DIR__"npc/whitejz" : 3,
]));
	set("coor/x",520);
  set("coor/y",420);
   set("coor/z",70);
   setup();
}
	    	
