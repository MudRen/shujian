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
                "west" : __DIR__"banruo",
              
        ]));
		set("objects",([
		__DIR__"npc/dizi-f" : 1,
	__DIR__"npc/dizi-m" : 1,
			]) );
        set("coor/x",-290);
  set("coor/y",-320);
   set("coor/z",40);
   setup();
}
