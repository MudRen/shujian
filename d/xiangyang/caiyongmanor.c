// /d/xiangyang/caiyongmanor.c

inherit ROOM;

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
������ǰ���Ǻ�ĩ���˲������ӵ�ׯԺ����Ů���ļ��������ڴˡ��ܲپ�
��ʱ���ݷù��������¹���Ǩ���������Ƕ��˷��ˡ�
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"  : "/d/changan/southroad3",
                "north" : __DIR__"caiyongtomb",
        ]));

        setup();
}

