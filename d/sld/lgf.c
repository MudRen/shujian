// lgf.c
// ������
inherit ROOM;
void create()
{
	set("short","������");
	set("long",@long
�˴�����̳����ƽʱ����ϰ��ĵط������п�ǽ�и������ܣ������
�Ų��ٱ������Ա߷��ż���ʯ���������м���һ��÷��׮�����ӵĴ�����
����ż���ɳ����
long);
	set("exits",([
	    "south" : __DIR__"road2",
]));
	set("objects",([
	__DIR__"npc/obj/hook" : 2,
]));	set("coor/x",500);
  set("coor/y",440);
   set("coor/z",90);
   setup();
}
	    	
