// /d/xingxiu/silk1.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Դ�˵�����ɳ�û��������ÿ��ʢ��ҹ����������ɳ�����Ի����
�͵ơ���ɽ��ˮ��Ⱥ�廷�ţ�Ұ�����ף��滨�����������վ������˾��ס�
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "northwest" : __DIR__"silk1a",
                "northeast" : __DIR__"silk",
        ]));

        setup();
}

#include "/d/xingxiu/job2.h";