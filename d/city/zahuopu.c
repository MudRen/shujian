// Room: /city/zahuopu.c

inherit MISC_ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG                                 
����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ���ƹ�
�����������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ���صĶ�
����̯������һ������(zhaopai)��
    ��ǰ���˸�����(sign)��
LONG
	);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
                __DIR__"npc/girl": 1,
	]));

	set("coor/x",110);
  set("coor/y",-20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

