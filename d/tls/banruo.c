inherit ROOM;
void create()
{
        set("short","����̨");
        set("long",@LONG
����̨��һ������ƽ̨�������е�����ϰ���յĵط���̨��
����ľ׮��÷��׮��ɳ����ɳ���������ʩ�͸���ɮ������������
����ĳ��ҵ�������һ���໥�д衣
LONG);
        set("outdoors","������");
        set("exits", ([
                "westdown" : __DIR__"yaotai",
                "northwest" : __DIR__"road2",
                "east" : __DIR__"banruo1",                
        ]));
		set("objects",([
		__DIR__"npc/liao-xiu" : 1,
			]) );
        set("coor/x",-300);
  set("coor/y",-320);
   set("coor/z",40);
   setup();
}
