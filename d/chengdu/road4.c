
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ������ʯ�̳ɵĴ������ʱ������������ҴҶ������ϱ�ͨ������
���񶼳ɶ��ˣ����߲�Զ��������ˡ�
LONG);
        set("outdoors", "�ɶ�");

        set("exits", ([
                "south" : __DIR__"dabeimen",
                "northeast" : __DIR__"road1",
        ]));

        setup(); 
}
