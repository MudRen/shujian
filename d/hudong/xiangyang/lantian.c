// /d/xiangyang/lantian.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Թų������񣬲������ʺã�Ҳ������ҩ���������ǳ�������������
����ȥ��������·��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
            "southeast" : __DIR__"shanxiroad2",
                "north" : "/d/changan/southroad3",
        ]));

        setup();
}

