
// Room: /city/kedian.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", CYN"�м��ջ"NOR);
        set("long", @LONG
�������ݳǱ���һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�
ѡ��������ţ��������������������صķ������顣��С����������
æ������ת���Ӵ�����ǻ�����Ŀ��ˡ������Ｘλ����������Ĵ�
��Χ��һ�����Ӳ�֪��������ʲô,�͵�����˴Ӳ�¶�棬��������˭��
�и��ָ����Ĳ²⡣ǽ�Ϲ���һ������(paizi)��
LONG
        );

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹһ��������\n",
        ]));

        set("exits", ([
                "west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
        ]));
        setup();
}

//�Ǿ���
int is_mirror() { return 1; }
