// õ�������.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
// amount: ��λ��gold

void create()
{
        set("short", HIG"õ������"NOR);
        set("long", @LONG
�����ƹ�һ�����Ƴ����磬ӭ��ǽ�Ϲ���һ����õ�庬¶��ͼ��������
�Σ�������֣���������ӯ�ҡ����ڳ����ݻ���������һ�ŵ��ľ����Ƕ
���Բ��������ʮ���������������ֺ�ľ�Σ��������磬�������ԡ�
    �����������¥��õ����������ƽ����һ�ݲ˵�(menu)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"zxlpath",
        ]));

        set("item_desc", ([
                "menu": @TEXT
�а��ʽ��ϯ, ��ӭ�ݹˣ�

        order marry:    �������        (3000���ƽ�)

        order player:   Ⱥ������        (5000���ƽ�)

        order end:      ��  ��

TEXT
        ]) );

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }