// Room: /d/putian/road08.c
// Lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
խխ��ʯ�׼�������ɽ�����죬ɽ�紵��������һ�������⡣ɽ����Ȼ���Ǻ�
���ͣ�����Ҳ��Щ�������ۿ���������ɮ�˽�����ɣ��������Ծ���������������
�������书��
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"road07",
                "southup" : __DIR__"shanmen",
        ]));

        set("objects",([
        	__DIR__"npc/jxiang-ke.c" : 2,
        ]));

        set("outdoors", "����");
        setup();
}

