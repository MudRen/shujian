// Room: xiaodian.c ����С��

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ���ª�����������ſڹ��ſ����˼������ӵ�ľ���ơ��������Ҳ�����
���������ɢ���ż����ƾɵ����Σ����ź��Ļҳ���ǽ�ǽ��Ÿ�֩������
LONG
	);

	set("exits", ([
		"north" : __DIR__"tianhu",
	]));
        set("objects", ([
         __DIR__"npc/wuchou1" : 1,
         __DIR__"npc/wuchou2" : 1,
         __DIR__"npc/wuchou3" : 1,
         __DIR__"npc/wuchou4" : 1,
         __DIR__"npc/wuchou5" : 1
       ]));
	set("coor/x",-250);
  set("coor/y",130);
   set("coor/z",0);
   setup();
}
