inherit ROOM;

void create()
{
        set("short", "Ӫ����");
        set("long", @LONG
�����ɹŹ�����������ʱ��Ӫ��Ӫ���м��������ſ��׵Ľ���������ȥ��
�ں�һ��������������ıʿ���˴�����̸�ۡ���ִ��ʲô��Ӫ�����м���ʿ��
��Ѳ�ߡ�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("objects", ([
                __DIR__"npc/weishi" : 3,
                __DIR__"npc/mengge" : 1,
        ]));

        set("exits", ([
                "out" : __DIR__"junying",
        ]));

//         set("no_fight",1);

	setup();
}
int valid_leave(object me)
{
    if(me->query_temp("xyjob/mg_attack") 
    && !me->query_temp("xyjob/attack_ready"))
    return notify_fail("����ʱ��δ������Ҫ���������\n");
    return ::valid_leave(me);
}
