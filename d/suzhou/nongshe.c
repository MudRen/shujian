// nongshe.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "ũ��");
        set("long",@long
����һ����ͨ��ũ�ᣬ��������൱��ª�����ϵ�é��Ҳ�����룬¶����
�����촲��һλũ���������ű߳麵�̡�
long);
	set("outdoors", "suzhou");

	set("exits",([
		"west" : __DIR__"caoebei",
	]));

	set("objects", ([
		__DIR__"npc/axiang" : 1,
	]));

	set("coor/x",50);
  set("coor/y",-250);
   set("coor/z",0);
   setup();
}
