// Room: d/xiangyang/zahuopu.c

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
        set("xyjob", 1);
        set("item_desc", ([
                "zhaopai": "���� \"list\" �г������\"buy\" ���ϰ幺�\n",
        ]));
        set("exits", ([
                "west" : __DIR__"dcx2",
        ]));
        set("objects", ([
                __DIR__"npc/niulaoban": 1,
        ]));

	set("incity",1);
	setup();
}
