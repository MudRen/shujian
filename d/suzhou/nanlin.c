// nanlin.c ���� ԽŮ����֮ס��
// By Jpei

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@long
��������أ��㲻����ǰһ�������۾��������деĴ������֡��ڼ������裬
��Գ��Ԯ���������Ρ����Ų��������֣�ֻ���������䣬�Ŀ�������
long);
	set("outdoors", "suzhou");

	set("exits",([
                "south" : __DIR__"tielingguan",
	]));

	set("objects", ([
                __DIR__"npc/aqing" : 1,
	]));

	set("coor/x",50);
  set("coor/y",-250);
   set("coor/z",0);
   setup();
}
