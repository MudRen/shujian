
inherit ROOM;

void create()
{
        set("short", "��ջ��¥");
        set("long", @LONG
���������������ջ�Ķ�¥��¥���������ڣ���ʱƮ����һ����������
�Ŀ�����ζ����������˿����ڴ������������˯һ����
LONG);
        set("sleep_room", 1);
        set("no_fight", 1);
	set("hotal", 1);

        set("exits", ([ 
             "down" : __DIR__"kezhan",
        ]));

	setup();
}
