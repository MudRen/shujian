// Room: d/jiaxing/zahuopu.c

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
		"south" : __DIR__"dbianmen",
	]));
	set("objects", ([
		__DIR__"npc/laoban": 1,
	]));
	setup();
}

