// Room: /d/xianyang/xiaocd.c
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short", "С�Ե�");
        set("long", @LONG
����һ��������¡��С�Ե꣬���������������֣�Ϊ������ĳ��������
�����������ģ�����Щ��·��վ��������š��������м������������ڴ���̸
����ʲô��������������ֵĴ��š�
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"bcx4",
        ]));

        set("objects", ([
                __DIR__"npc/paotang" : 1,
                "/d/huashan/npc/haoke":2,
        ]));

        set("incity",1);
	setup();
}
