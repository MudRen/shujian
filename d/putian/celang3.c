// Room: /d/putian/celang3.c ����
// lklv 2001.7.22

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ľ��ĳ��ȣ����ȶ��ϵĻ����ϻ���������еĹ��£�������
�Ǻ�ɫ�������ߣ���������һ��ϸ���ʯ�ӡ��ϱ����涼�и������ţ��ֱ�ͨ
��ǰ��Ժ��ż����Сɳ�ֵ���ͷ�Ҵ��߹���
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan3",
                "south" : __DIR__"xiaoyuan5",

        ]));
        setup();
}
