// Room: /d/putian/youcaidi.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "�Ͳ˵�");
        set("long", @LONG
����һ��Ƭ�Ͳ˵أ���Ƭ��Ƭ���Ͳ˻����ĵ������ǡ������������Ų˻�
���������۷������ȥ��æµ����ͣ����ͷ�Ϸ���һ���ⵣ���Ա߻���һ����
ľͰ�������а���ˮ��
LONG
        );

        set("exits", ([
                "south" : __DIR__"xl7",
        ]));
        set("outdoors", "����");
        setup();
}
