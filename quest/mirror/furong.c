// ܽ�������.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
// amount: ��λ��gold

void create()
{
        set("short", HIY"ܽ������"NOR);
        set("long", @LONG
�����ƹ�һ�����̳����磬ӭ��ǽ�Ϲ���һ����ܽ�س�ˮ��ͼ�����ʲ�
�棬״�����ţ�����׿�������ڳ����ݻ���������һ�ŵ��ľ����Ƕ���
Բ��������ʮ���������������ֺ�ľ�Σ��������磬�������ԡ�
    �����������¥��õ����������ƽ����һ�ݲ˵�(menu)��
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"zxlpath",
        ]));

        set("item_desc", ([
                "menu": @TEXT
�а��ʽ��ϯ, ��ӭ�ݹˣ�

        order birthday: ף����        (400���ƽ�)

        order marry:    ������        (800���ƽ�)

        order player:   Ⱥ����        (1000���ƽ�)

        order end:      ��  ��

TEXT
        ]) );

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }