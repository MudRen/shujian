// hulmlgf.c
// ������������
inherit ROOM;
void create()
{
	set("short","������");
	set("long",@long
�˴��ǻ����Ž���ƽʱ����ϰ��ĵط������п�ǽ�и������ܣ�����
���Ų��ٱ������Ա߷��ż���ʯ���������м���һ��÷��׮�����ӵĴ���
������ż���ɳ����
long);
	set("exits",([
	    "east" : __DIR__"hulm",
]));
	set("objects",([
		__DIR__"npc/obj/bian" : 2,
]));
        set("coor/x",490);
  set("coor/y",440);
   set("coor/z",70);
   setup();
}
	    	
