inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�
С������ɢ�������ġ�ҩ���������ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG
	);
        set("objects",([
           __DIR__"npc/laoban" : 1,
           __DIR__"npc/huoji" : 1,
         ]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));
	set("coor/x",150);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}

