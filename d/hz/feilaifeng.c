// /u/beyond/hz/feilaifeng.c ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"������"NOR);
        set("long", @LONG
���������������ʯ���ϵĸ����������ұ��Ͽ��а����ӷ𡢹�����
����̻��¶�ء�Ц����������շ�����������һ������ұ�ʯ����
���С�������������������ȫ�����ף�����ͭ�ᣬ�������ݵ�����ʨ�ӱ�
�ϣ�ʮ��������
LONG
        );
        set("exits", ([
            "west" : __DIR__"qsddao3",
"southeast" : __DIR__"yxsdong",
]));
              set("objects",([
//                 "/clone/npc/gui" : 1,
                "/d/huashan/npc/gui" : 1,
//�����gui by daidai
                "/clone/npc/gui2" : 1,
        ]));

        setup();
}
