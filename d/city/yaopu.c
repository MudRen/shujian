// Room: /city/yaopu.c

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ�ҩ���ϰ����ڲ輸�ԣ����Ժ��Ų衣һ��С���վ�ڹ�̨
���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
LONG
	);
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
������ҩ���ϰ����顣\n",
	]));

	set("objects", ([
		__DIR__"npc/yaopu-laoban" : 1,
		__DIR__"npc/huoji" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"dongdajie1",
	]));

	set("coor/x",120);
  set("coor/y",0);
   set("coor/z",0);
   set("incity",1);
	setup();
}

