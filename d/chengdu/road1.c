
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ������ʯ�̳ɵĴ������ʱ������������ҴҶ������ϱ�ͨ������
���񶼳ɶ��ˣ����߲�Զ��������ˡ�����Ķ�����һ��Ρ��ĸ�ɽ��
LONG);
        set("outdoors", "�ɶ�");

        set("exits", ([
                "southwest" : __DIR__"road4",
                "north" : "/d/lanzhou/qingcheng",
                "east" : "/d/zhiye/gaoshan0",
        ]));

        setup(); 
}
