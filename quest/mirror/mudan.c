// ĵ�������.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

// amount: ��λ��gold

void create()
{
        set("short", HIR"ĵ������"NOR);
        set("long", @LONG
�����ƹ�һ����������磬ӭ��ǽ�Ϲ���һ����ĵ�����ޡ�ͼ��ĵ����
�й����������Ը������ơ�ͼ�����: �ľ����˳ʶ��㣬��԰��ɫ��Ⱥ����
��������һ��ĵ�����⾫�����ڳ����ݻ���������һ�ŵ��ľ����Ƕ��
��Բ��������ʮ���������������ֺ�ľ�Σ��������磬�������ԡ�
    �����������¥��õ����������ƽ����һ�ݲ˵�(menu)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"zxlpath",
        ]));

        set("item_desc", ([
                "menu": @TEXT
�а��ʽ��ϯ, ��ӭ�ݹˣ�

        order marry:    ���Ŷ�����        (1�����ƽ�)

        order end:      ��  ��

TEXT
        ]) );

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }