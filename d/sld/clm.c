// clm.c
// ����������
inherit ROOM;
void create()
{
	set("short","������������");
	set("long",@long
�˴��ǳ����ŵ��������������Ŵ��Ŵ���һ�Ŵ�������ǽ���ã�����
�����ε���Χ������ֻ���ʿ�ǽ���š�
long);
	set("exits",([
	    "east" : __DIR__"clmws",
          "west" : __DIR__"clmlgf",
          "out" : __DIR__"sanpo3",
]));
set("objects",([
"/kungfu/class/sld/wg" : 1,
__DIR__"npc/redjz" : 3,
]));
	set("coor/x",490);
  set("coor/y",450);
   set("coor/z",20);
   setup();
}
	    	
