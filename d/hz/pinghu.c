// /u/beyond/hz/pinghuqiuyue.c ƽ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"ƽ������"NOR);
        set("long", @LONG
ƽ���������������ˮ��ʮ�ֿ�����¥��ǰ��һ������ƽ̨����ֱ�쵽
���У�������ˮ��ƽ̨��ˮ����ƽ�����ߵ�ƽ����Ұ���������ٺ����µĺ�
�ط����ڴ�������ɽ���̲����죬Ⱥɽ�´䣬ɽ��ˮɫ�ޱ��������ر����
�µ���֮ʱ�������ˮ���������������ʤ��
LONG
        );
        set("exits", ([
            "east" : __DIR__"baidi",
	]));
	set("outdoors", "����");
	setup();
}
