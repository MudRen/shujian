// #include <room.h>

inherit ROOM;

void create()
{
        set("short", "�Խ���");
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
        );

        set("exits", ([
                 "south": __DIR__"wumiao",
]));
set("item_desc", ([
                "sign": @TEXT
   ��̨�۽�
���¹���
TEXT
        ]) );


        setup();
}
//�Ǿ���
int is_mirror() { return 1; }