// /area/jiangbei/wudang/qtguan.c ��̨��
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"��̨��"NOR);
        set("long", @LONG
��̨��λ���䵱ɽ�����嶫�ϰ˹��ﴦ����Ϊ��̨�Ϲۡ��йۺ��¹�����
������Ԫ�����䵱ɽ��ʮ���������ĵ���֮һ����̨���۸��зǳ���������
�֣��Ϲ۽С������̨�����й۽С�������̨�����¹۽С�������̨������֮
���ɽ������޽��ж�����Ժ��֮����ͤ������������������֮���߶�������
�����죬���겻ʪЬ����˵�����ɼ���̨�Ǻ�������ġ�
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"langmei",
                "eastup" : __DIR__"gsdao6",
        ]));

        set("no_clean_up", 0);

        set("objects",([
               __DIR__"npc/daotong" : 1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
